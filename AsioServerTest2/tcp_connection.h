#include <iostream>
#include <string>
#include <boost/bind/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;




class tcp_connection
	: public boost::enable_shared_from_this<tcp_connection>
{
private:

	static const int BUFFER_SIZE = 1024;
	tcp::socket socket_;
	char recv_buf_[BUFFER_SIZE];

	tcp_connection(boost::asio::io_context& io_context);

public:
	typedef boost::shared_ptr<tcp_connection> pointer;
	~tcp_connection();


	static pointer create(boost::asio::io_context& io_context)
	{
		return pointer(new tcp_connection(io_context));
	}

	tcp::socket& socket();
	void on_accepted();


private:

	void write(__in const void* data, __in const size_t size);
	void on_write_complete(const boost::system::error_code& /*error*/, size_t /*bytes_transferred*/);
	
	void read();
	void on_read_complete(__in const boost::system::error_code& error, __in size_t bytes_received);
	
	void close();
};
