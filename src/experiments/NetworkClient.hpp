#ifndef NetworkClient_hpp
#define NetworkClient_hpp

#include <thread>
#include <asio.hpp>

#include "N2MStandardPacket.hpp"
#include "M2NStandardPacket.hpp"

class NetworkClient {
public:
    NetworkClient();
    ~NetworkClient();
    void open(std::string ip_address, int port_number);
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
    asio::io_service *io_service;
    asio::ip::udp::resolver *resolver;
    asio::ip::udp::resolver::query *query;
    asio::ip::udp::endpoint *receiver_endpoint;
    asio::ip::udp::socket *socket;
};

#endif // NetworkClient_hpp
