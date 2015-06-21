#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <asio.hpp>

#include "NetworkClient.hpp"
#include "N2MStandardPacket.hpp"
#include "M2NStandardPacket.hpp"

NetworkClient::NetworkClient()
{
    is_running = false;
}

NetworkClient::~NetworkClient()
{
    is_running = false;
    send_thread->join();
    receive_thread->join();
    delete send_thread;
    delete receive_thread;
    delete socket;
    delete receiver_endpoint;
    delete io_service;
}

void NetworkClient::open(std::string ip_address, int port_number)
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

void NetworkClient::start()
{
    receive_thread = new std::thread(&NetworkClient::run_receive_thread, this);
    send_thread = new std::thread(&NetworkClient::run_send_thread, this);
}

void NetworkClient::run_send_thread()
{
    is_running = true;
    while (is_running) {
        send_packet();
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}

void NetworkClient::run_receive_thread()
{
    is_running = true;
    while (is_running)
        receive_packet();
}

N2MStandardPacket *NetworkClient::get_n2m_standard_packet()
{
    return &n2m_standard_packet;
}

M2NStandardPacket *NetworkClient::get_m2n_standard_packet()
{
    return &m2n_standard_packet;
}

void NetworkClient::receive_packet()
{
    try
    {
        unsigned char recv_buffer[n2m_standard_packet.size()];
        asio::error_code error;
        asio::ip::udp::endpoint sender_endpoint;
        socket->receive_from(asio::buffer(recv_buffer, n2m_standard_packet.size()), sender_endpoint, 0, error);
        if (error && error != asio::error::message_size)
            throw asio::system_error(error);
        n2m_standard_packet.read_buffer(recv_buffer);
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}

void NetworkClient::send_packet()
{
    try
    {
        unsigned char send_buffer[m2n_standard_packet.size()];
        m2n_standard_packet.get_buffer(send_buffer);
        asio::error_code ignored_error;
        socket->send_to(asio::buffer(send_buffer, n2m_standard_packet.size()), *receiver_endpoint, 0, ignored_error);
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}
