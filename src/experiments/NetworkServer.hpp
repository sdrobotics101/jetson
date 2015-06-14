#ifndef NetworkServer_hpp
#define NetworkServer_hpp

#include <thread>
#include <boost/array.hpp>
#include <boost/asio.hpp>

#include "N2MStandardPacket.hpp"
#include "M2NStandardPacket.hpp"

class NetworkServer {
public:
    NetworkServer();
    ~NetworkServer();
    void open();
    void start();
    N2MStandardPacket *get_n2m_standard_packet();
    M2NStandardPacket *get_m2n_standard_packet();
private:
    void run_send_thread();
    void run_receive_thread();
    void receive_packet();
    void send_packet();
    N2MStandardPacket n2m_standard_packet;
    M2NStandardPacket m2n_standard_packet;
    bool is_running;
    std::thread *send_thread;
    std::thread *receive_thread;
    boost::asio::io_service *io_service;
    boost::asio::ip::udp::socket *socket;
    boost::asio::ip::udp::endpoint remote_endpoint;
    bool determined_remote_endpoint;
};

#endif // NetworkServer_hpp
