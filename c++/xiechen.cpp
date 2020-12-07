#include <boost/asio.hpp>
#include <boost/asio/spawn.hpp>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp> 
#include <string>
#include <ctime>
#include <iostream>
#include <boost/enable_shared_from_this.hpp>
using namespace boost::asio;
using std::cerr; using std::endl;
io_service io_service_;
class session: public boost::enable_shared_from_this<session>
{
public:
    explicit session(ip::tcp::socket socket):
    sock_(std::move(socket)),
    strand_(io_service_),
    uuid_(std::rand())
    {}
    
    ~session() { cerr << "~sessoin ->" << uuid_ << endl; }
    
    void go()
    {
        auto self(shared_from_this());
        boost::asio::spawn(strand_, 
                boost::bind(&session::do_echo, self, _1));
    }
    void do_echo(yield_context yield)
    {
        char data[128];  
        std::size_t n = sock_.async_read_some(boost::asio::buffer(data), yield);
        cerr << "RECVED:【" << data << "】->" << uuid_ <<endl;
        std::time_t now = std::time(nullptr);
        std::string time_str = std::ctime(&now);
        async_write(sock_, buffer(time_str), yield);
        sock_.shutdown(ip::tcp::socket::shutdown_send);
    }
private:
    ip::tcp::socket sock_;
    io_service::strand strand_;
    std::size_t  uuid_;
};
void start_accept(yield_context yield)
{
    ip::tcp::acceptor acceptor(io_service_, ip::tcp::endpoint(ip::tcp::v4(), 2016));
    
    for (;;) {
        boost::system::error_code ec;
        ip::tcp::socket socket(io_service_);
        
        acceptor.async_accept(socket, yield[ec]);
        if(!ec)
            boost::make_shared<session>(std::move(socket))->go();
    }
}
int main(int argc, char* argv[])
{
    boost::asio::spawn(io_service_, start_accept);
    io_service_.run();
}