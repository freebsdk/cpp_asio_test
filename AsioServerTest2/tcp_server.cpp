#include "tcp_server.h"




tcp_server::tcp_server(boost::asio::io_context& io_context)
	: io_context_(io_context), acceptor_(io_context, tcp::endpoint(tcp::v4(), 9090))
{
	start_accept();
}




void tcp_server::start_accept()
{
    tcp_connection::pointer new_connection =
        tcp_connection::create(io_context_);

    acceptor_.async_accept(new_connection->socket(),
        boost::bind(&tcp_server::on_complete_accept, this, new_connection,
            boost::asio::placeholders::error));
}




void tcp_server::on_complete_accept(tcp_connection::pointer new_connection,
    const boost::system::error_code& error)
{
    if (!error)
    {
        new_connection->on_accepted();
        conn.push_back(new_connection); // for test only
    }

    start_accept();
}