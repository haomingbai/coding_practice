#include <array>
#include <boost/asio.hpp>
#include <iostream>
#include <memory>
#include <string>
#include <thread>

using boost::asio::ip::tcp;

// 模拟耗时较长的函数
std::string long_task(const std::string& input) {
  // 这里可以是任意耗时操作，如计算、I/O 等。
  std::this_thread::sleep_for(std::chrono::seconds(5));
  return "Echo: " + input;
}

class EchoSession : public std::enable_shared_from_this<EchoSession> {
 public:
  EchoSession(tcp::socket socket, boost::asio::io_context& io_context)
      : socket_(std::move(socket)), io_context_(io_context) {}

  void start() { do_read(); }

 private:
  void do_read() {
    auto self = shared_from_this();
    socket_.async_read_some(
        boost::asio::buffer(data_),
        [this, self](boost::system::error_code ec, std::size_t length) {
          if (!ec) {
            std::string request(data_.data(), length);
            // 在新线程中执行耗时任务，避免阻塞io_context线程
            std::thread([this, self, request]() {
              std::string response = long_task(request);
              // 将写操作的回调回到io_context中序列化执行
              post(io_context_,
                   [this, self, response]() { do_write(response); });
            }).detach();
          }
          // 出现错误会自动销毁session
        });
  }

  void do_write(const std::string& response) {
    auto self = shared_from_this();
    boost::asio::async_write(
        socket_, boost::asio::buffer(response.data(), response.size()),
        [this, self](boost::system::error_code ec, std::size_t /*length*/) {
          if (!ec) {
            // 写完后继续读取下一个请求
            do_read();
          }
        });
  }

  tcp::socket socket_;
  boost::asio::io_context& io_context_;
  std::array<char, 1024> data_;
};

class EchoServer {
 public:
  EchoServer(boost::asio::io_context& io_context, unsigned short port)
      : acceptor_(io_context, tcp::endpoint(tcp::v4(), port)),
        io_context_(io_context) {
    do_accept();
  }

 private:
  void do_accept() {
    acceptor_.async_accept([this](boost::system::error_code ec,
                                  tcp::socket socket) {
      if (!ec) {
        std::make_shared<EchoSession>(std::move(socket), io_context_)->start();
      }
      do_accept();
    });
  }

  tcp::acceptor acceptor_;
  boost::asio::io_context& io_context_;
};

int main() {
  try {
    boost::asio::io_context io_context;
    EchoServer server(io_context, 12345);
    std::cout << "Echo server running on port 12345..." << std::endl;
    io_context.run();
  } catch (std::exception& e) {
    std::cerr << "Exception: " << e.what() << std::endl;
  }
  return 0;
}

