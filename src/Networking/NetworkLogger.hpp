#ifndef NetworkLogger_hpp
#define NetworkLogger_hpp

#include <cstdint>
#include <asio.hpp>

#include "N2MStandardPacket.hpp"
#include "M2NStandardPacket.hpp"

class NetworkLogger {
public:
    ~NetworkLogger();
    void open(std::string ip_address, int port_number);
    void send_packet(unsigned char send_buffer[], size_t send_buffer_size);
private:
    asio::io_service *io_service;
    asio::ip::udp::resolver *resolver;
    asio::ip::udp::resolver::query *query;
    asio::ip::udp::endpoint *receiver_endpoint;
    asio::ip::udp::socket *socket;
};

#endif // NetworkLogger_hpp
