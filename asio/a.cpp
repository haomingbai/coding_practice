#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/thread.hpp>
#include <functional>
#include <iostream>

using namespace std;
using namespace boost::asio;

typedef boost::shared_ptr<ip::tcp::socket> socket_ptr;

void handle_accept(socket_ptr sock, const boost::system::error_code &err);
void start_accept(socket_ptr sock);

io_service service;
ip::tcp::endpoint ep(ip::tcp::v4(), 2001); // 监听端口2001
ip::tcp::acceptor acc(service, ep);
socket_ptr sock(new ip::tcp::socket(service));

int main()
{
    start_accept(sock);
    service.run();
}

void start_accept(socket_ptr sock)
{
    acc.async_accept(*sock, boost::bind(handle_accept, sock, _1));
}

void handle_accept(socket_ptr sock, const boost::system::error_code &err)
{
    if (err)
        return;
    // 从这里开始, 你可以从socket读取或者写入
    socket_ptr nsock(new ip::tcp::socket(service));
    start_accept(nsock);
}