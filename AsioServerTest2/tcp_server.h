#pragma once
#include "tcp_connection.h"

using boost::asio::ip::tcp;





class tcp_server
{
public:

    tcp_server(boost::asio::io_context& io_context);

private:
    
    std::list<tcp_connection::pointer> conn;
    void start_accept();
    void on_complete_accept(tcp_connection::pointer new_connection, const boost::system::error_code& error);

    boost::asio::io_context& io_context_;
    tcp::acceptor acceptor_;
};
