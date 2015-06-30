#ifndef NetworkServer_hpp
#define NetworkServer_hpp

#include <thread>
#include <asio.hpp>

#include "N2MStandardPacket.hpp"
#include "M2NStandardPacket.hpp"
#include "NetworkLogger.hpp"

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
    NetworkLogger n2m_logger;
    NetworkLogger m2n_logger;
    bool is_running;
    std::thread *send_thread;
    std::thread *receive_thread;
    asio::io_service *io_service;
    asio::ip::udp::socket *socket;
    asio::ip::udp::endpoint remote_endpoint;
    bool determined_remote_endpoint;
};

#endif // NetworkServer_hpp
