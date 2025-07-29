#include <algorithm>
#include <boost/asio/dispatch.hpp>
#include <boost/asio/strand.hpp>
#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/version.hpp>
#include <boost/config.hpp>
#include <cstdlib>
#include <iostream>
#include <memory>
#include <thread>
#include <vector>

namespace beast = boost::beast;    // from <boost/beast.hpp>
namespace http = beast::http;      // from <boost/beast/http.hpp>
namespace net = boost::asio;       // from <boost/asio.hpp>
using tcp = boost::asio::ip::tcp;  // from <boost/asio/ip/tcp.hpp>

//------------------------------------------------------------------------------

// 报告错误并退出的辅助函数
void fail(beast::error_code ec, char const* what) {
  std::cerr << what << ": " << ec.message() << "\n";
}

// 处理单个 HTTP 请求
class http_session : public std::enable_shared_from_this<http_session> {
  // 这是异步操作中推荐使用的 `strand`。
  // 它确保了回调不会并发执行，这对于在一个连接上按顺序处理读写操作非常重要。
  beast::tcp_stream stream_;
  beast::flat_buffer buffer_;
  http::request<http::string_body> req_;

 public:
  // 构造函数，获取套接字的所有权
  explicit http_session(tcp::socket&& socket) : stream_(std::move(socket)) {}

  // 启动异步操作
  void run() {
    // 我们需要在 run() 返回之前分派一个操作，
    // 否则 session 对象将在我们有机会启动任何异步操作之前就被销毁。
    net::dispatch(
        stream_.get_executor(),
        beast::bind_front_handler(&http_session::do_read, shared_from_this()));
  }

 private:
  void do_read() {
    // 清空上一次的请求
    req_ = {};

    // 设置超时。在实际应用中，你可能希望在每次操作后重置超时。
    stream_.expires_after(std::chrono::seconds(30));

    // 异步读取一个请求
    http::async_read(
        stream_, buffer_, req_,
        beast::bind_front_handler(&http_session::on_read, shared_from_this()));
  }

  void on_read(beast::error_code ec, std::size_t bytes_transferred) {
    boost::ignore_unused(bytes_transferred);

    // 如果客户端关闭连接
    if (ec == http::error::end_of_stream) return do_close();

    if (ec) return fail(ec, "read");

    // 发送响应
    send_response(handle_request(std::move(req_)));
  }

  // 这个函数生成一个响应来匹配收到的请求。
  // 在这个例子中，我们总是发送一个 "Hello, world!" 的响应。
  template <class Body, class Allocator>
  http::response<http::string_body> handle_request(
      http::request<Body, http::basic_fields<Allocator>>&& req) {
    // 返回一个通用的响应
    http::response<http::string_body> res{http::status::ok, req.version()};
    res.set(http::field::server, BOOST_BEAST_VERSION_STRING);
    res.set(http::field::content_type, "text/html; charset=utf-8");
    res.keep_alive(req.keep_alive());
    res.body() =
        "<h1>Hello, Boost.Beast!</h1><p>This is a multi-threaded server.</p>";
    res.prepare_payload();
    return res;
  }

  void send_response(http::response<http::string_body>&& res) {
    // 响应是临时的，所以我们需要将其序列化到一个成员变量中。
    // 我们使用一个 lambda 作为 completion handler 的一部分来延长 `res`
    // 的生命周期。 这是 C++11 lambda 的一个很好的应用。
    auto sp =
        std::make_shared<http::response<http::string_body>>(std::move(res));

    // 异步写入响应
    http::async_write(stream_, *sp,
                      [self = shared_from_this(), sp](beast::error_code ec,
                                                      std::size_t bytes) {
                        self->on_write(ec, bytes, sp->need_eof());
                      });
  }

  void on_write(beast::error_code ec, std::size_t bytes_transferred,
                bool close) {
    boost::ignore_unused(bytes_transferred);

    if (ec) return fail(ec, "write");

    if (close) {
      // 如果响应中指定了 "Connection: close"，我们就关闭连接
      return do_close();
    }

    // 我们已经完成了，所以再次读取下一个请求
    do_read();
  }

  void do_close() {
    // 优雅地关闭套接字
    beast::error_code ec;
    stream_.socket().shutdown(tcp::socket::shutdown_send, ec);

    // 在这里，我们不关心错误代码，因为套接字可能已经被远程对等方关闭了。
  }
};

//------------------------------------------------------------------------------

// 接受传入连接并为每个连接启动一个会话
class listener : public std::enable_shared_from_this<listener> {
  net::io_context& ioc_;
  tcp::acceptor acceptor_;

 public:
  listener(net::io_context& ioc, tcp::endpoint endpoint)
      : ioc_(ioc), acceptor_(net::make_strand(ioc)) {
    beast::error_code ec;

    // 打开 acceptor
    acceptor_.open(endpoint.protocol(), ec);
    if (ec) {
      fail(ec, "open");
      return;
    }

    // 允许地址重用
    acceptor_.set_option(net::socket_base::reuse_address(true), ec);
    if (ec) {
      fail(ec, "set_option");
      return;
    }

    // 绑定到服务器地址
    acceptor_.bind(endpoint, ec);
    if (ec) {
      fail(ec, "bind");
      return;
    }

    // 开始监听连接
    acceptor_.listen(net::socket_base::max_listen_connections, ec);
    if (ec) {
      fail(ec, "listen");
      return;
    }
  }

  // 启动接受循环
  void run() { do_accept(); }

 private:
  void do_accept() {
    // 下一个连接将使用这个套接字
    // acceptor_ 的 strand 确保了在并发调用 do_accept 时，
    // 我们每次都会创建一个新的套接字。
    acceptor_.async_accept(
        net::make_strand(ioc_),
        beast::bind_front_handler(&listener::on_accept, shared_from_this()));
  }

  void on_accept(beast::error_code ec, tcp::socket socket) {
    if (ec) {
      fail(ec, "accept");
      return;  // To avoid infinite loop
    } else {
      // 创建 http_session 并启动它
      std::make_shared<http_session>(std::move(socket))->run();
    }

    // 接受下一个连接
    do_accept();
  }
};

//------------------------------------------------------------------------------

int main(int argc, char* argv[]) {
  // 检查命令行参数
  if (argc != 4) {
    std::cerr << "Usage: http-server-async <address> <port> <threads>\n"
              << "Example:\n"
              << "    http-server-async 0.0.0.0 8080 1\n";
    return EXIT_FAILURE;
  }
  auto const address = net::ip::make_address(argv[1]);
  auto const port = static_cast<unsigned short>(std::atoi(argv[2]));
  auto const threads = std::max<int>(1, std::atoi(argv[3]));

  // io_context 是所有 I/O 的核心
  net::io_context ioc{threads};

  // 创建并启动监听器以接受传入连接
  std::make_shared<listener>(ioc, tcp::endpoint{address, port})->run();

  // 创建工作线程池
  std::vector<std::thread> v;
  v.reserve(threads - 1);
  for (auto i = threads - 1; i > 0; --i) v.emplace_back([&ioc] { ioc.run(); });

  // 主线程也加入工作
  std::cout << "Server starting at " << address << ":" << port << " with "
            << threads << " threads.\n";
  ioc.run();

  // (可选) 如果 ioc.run() 返回，意味着所有工作都已完成。
  // 在一个 web 服务器中，这通常只在服务器被停止时发生。
  // 等待所有工作线程完成。
  for (auto& t : v) t.join();

  return EXIT_SUCCESS;
}
