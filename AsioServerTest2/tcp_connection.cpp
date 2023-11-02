#include "tcp_connection.h"







tcp_connection::~tcp_connection()
{

}




tcp::socket& tcp_connection::socket()
{
	return socket_;
}




void tcp_connection::on_accepted()
{
    read();
}




tcp_connection::tcp_connection(boost::asio::io_context& io_context)
	: socket_(io_context)
{

}




void tcp_connection::write(__in const void* data, __in const size_t size)
{
	boost::asio::async_write(socket_,
		boost::asio::buffer(data, size),
		boost::bind(&tcp_connection::on_write_complete,
			this,
			boost::asio::placeholders::error,
			boost::asio::placeholders::bytes_transferred)
	);
}




void tcp_connection::on_write_complete(const boost::system::error_code& /*error*/,
	size_t /*bytes_transferred*/)
{
}




void tcp_connection::read()
{
	memset(&recv_buf_, '\0', sizeof(recv_buf_));
	socket_.async_read_some(
		boost::asio::buffer(recv_buf_),
		boost::bind(&tcp_connection::on_read_complete,
			this,
			boost::asio::placeholders::error,
			boost::asio::placeholders::bytes_transferred)
	);
}




void tcp_connection::on_read_complete(__in const boost::system::error_code& error, __in size_t bytes_received)
{
	if (error)
	{
		printf("%s:%d", error.category().name(), error.value());
		close();
		return;
	}

	printf("%zd bytes received.\n", bytes_received);
	write(recv_buf_, bytes_received);

	read();
}




void tcp_connection::close()
{
	if (socket_.is_open())
	{
		socket_.shutdown(boost::asio::ip::tcp::socket::shutdown_receive);
		socket_.close();
	}
}




