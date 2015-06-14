#include <stdio.h>
#include <stdint.h>
#include <iostream>
#include <boost/array.hpp>
#include <boost/asio.hpp>

#include "N2MStandardPacket.hpp"
#include "M2NStandardPacket.hpp"

int main(int argc, char* argv[])
{
    N2MStandardPacket send_packet;
    M2NStandardPacket recv_packet;
    std::cout << recv_packet.size() << std::endl;
    send_packet.set_vel_x(123.4);
    unsigned char send_buffer[send_packet.size()];
    send_packet.get_buffer(send_buffer);
    std::cout << "Sending following data:" << std::endl;
    std::cout << "vel_x = " << send_packet.get_vel_x() << std::endl;
    try
    {
        boost::asio::io_service io_service;
        boost::asio::ip::udp::socket socket(io_service, boost::asio::ip::udp::endpoint(boost::asio::ip::udp::v4(), 8888));
        for (;;)
        {
            //boost::array<char, 1> recv_buf;
            unsigned char recv_buffer[recv_packet.size()];
            boost::asio::ip::udp::endpoint remote_endpoint;
            boost::system::error_code error;
            socket.receive_from(boost::asio::buffer(recv_buffer, recv_packet.size()), remote_endpoint, 0, error);
            if (error && error != boost::asio::error::message_size)
                throw boost::system::system_error(error);
            recv_packet.read_buffer(recv_buffer);

            // Print out recv_buffer
            std::cout << "recv_buffer = ";
            for (uint i = 0; i < recv_packet.size(); i++)
                std::cout << recv_buffer[i];
            std::cout << std::endl;

            // Print out recv_packet
            std::cout << "====== RECEIVED PACKET ======" << std::endl;
            std::cout << "header = " << recv_packet.get_header() << std::endl;
            std::cout << "pos_z = " << recv_packet.get_pos_z() << std::endl;
            std::cout << "orient_x = " << recv_packet.get_orient_x() << std::endl;
            std::cout << "orient_y = " << recv_packet.get_orient_y() << std::endl;
            std::cout << "orient_z = " << recv_packet.get_orient_z() << std::endl;
            std::cout << "health = " << recv_packet.get_health() << std::endl;
            std::cout << "bat_v = " << recv_packet.get_bat_v() << std::endl;
            std::cout << "=============================" << std::endl;

            boost::system::error_code ignored_error;
            socket.send_to(boost::asio::buffer(send_buffer, send_packet.size()), remote_endpoint, 0, ignored_error);
        }
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return EXIT_SUCCESS;
}
