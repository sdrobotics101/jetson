#include <iostream>
#include <thread>
#include <chrono>
#include <asio.hpp>

#include "NetworkServer.hpp"
#include "NetworkLogger.hpp"
#include "N2MStandardPacket.hpp"
#include "M2NStandardPacket.hpp"

NetworkServer::NetworkServer()
{
    is_running = false;
    determined_remote_endpoint = false;
}

NetworkServer::~NetworkServer()
{
    is_running = false;
    send_thread->join();
    receive_thread->join();
    delete send_thread;
    delete receive_thread;
    delete socket;
    delete io_service;
}

void NetworkServer::open()
{
    try
    {
        io_service = new asio::io_service();
        socket = new asio::ip::udp::socket(*io_service, asio::ip::udp::endpoint(asio::ip::udp::v4(), 8888));
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    n2m_logger.open("127.0.0.1", 8889);
    m2n_logger.open("127.0.0.1", 8890);
}

void NetworkServer::start()
{
    receive_thread = new std::thread(&NetworkServer::run_receive_thread, this);
    while (! determined_remote_endpoint);
    send_thread = new std::thread(&NetworkServer::run_send_thread, this);
}

void NetworkServer::run_send_thread()
{
    is_running = true;
    while (is_running) {
        send_packet();
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}

void NetworkServer::run_receive_thread()
{
    is_running = true;
    while (is_running)
        receive_packet();
}

N2MStandardPacket *NetworkServer::get_n2m_standard_packet()
{
    return &n2m_standard_packet;
}

M2NStandardPacket *NetworkServer::get_m2n_standard_packet()
{
    return &m2n_standard_packet;
}

void NetworkServer::receive_packet()
{
    try
    {
        unsigned char recv_buffer[m2n_standard_packet.size()];
        asio::error_code error;
        socket->receive_from(asio::buffer(recv_buffer, m2n_standard_packet.size()), remote_endpoint, 0, error);
        if (error && error != asio::error::message_size)
            throw asio::system_error(error);
        m2n_standard_packet.read_buffer(recv_buffer);
        m2n_logger.send_packet(recv_buffer, m2n_standard_packet.size());
        determined_remote_endpoint = true;
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}

void NetworkServer::send_packet()
{
    try
    {
        unsigned char send_buffer[n2m_standard_packet.size()];
        n2m_standard_packet.get_buffer(send_buffer);
        asio::error_code ignored_error;
        socket->send_to(asio::buffer(send_buffer, n2m_standard_packet.size()), remote_endpoint, 0, ignored_error);
        n2m_logger.send_packet(send_buffer, n2m_standard_packet.size());
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}
