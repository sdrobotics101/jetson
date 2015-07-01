#include <cstdint>
#include <iostream>
#include <string>
#include <asio.hpp>

#include "NetworkLogger.hpp"
#include "N2MStandardPacket.hpp"
#include "M2NStandardPacket.hpp"

NetworkLogger::~NetworkLogger()
{
    delete socket;
    delete receiver_endpoint;
    delete io_service;
}

void NetworkLogger::open(std::string ip_address, int port_number)
{
    try
    {
        io_service = new asio::io_service();
        receiver_endpoint = new asio::ip::udp::endpoint(asio::ip::address::from_string(ip_address), port_number);
        socket = new asio::ip::udp::socket(*io_service);
        socket->open(asio::ip::udp::v4());
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}

void NetworkLogger::send_packet(unsigned char send_buffer[], size_t send_buffer_size)
{
    try
    {
        asio::error_code ignored_error;
        socket->send_to(asio::buffer(send_buffer, send_buffer_size), *receiver_endpoint, 0, ignored_error);
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}
