#include <stdio.h>
#include <stdint.h>
#include <iostream>
#include <boost/array.hpp>
#include <boost/asio.hpp>

#include "N2MStandardPacket.hpp"

int main(int argc, char* argv[])
{
    N2MStandardPacket send_packet;
    unsigned char send_buffer[send_packet.size()];
    send_packet.get_buffer(send_buffer);
    printf("Send data: ");
    for (size_t i = 0; i < send_packet.size(); i++)
    {
        printf("%d", send_buffer[i]);
    }
    printf("\n");
    try
    {
        boost::asio::io_service io_service;
        boost::asio::ip::udp::socket socket(io_service, boost::asio::ip::udp::endpoint(boost::asio::ip::udp::v4(), 8888));
        for (;;)
        {
            boost::array<char, 1> recv_buf;
            boost::asio::ip::udp::endpoint remote_endpoint;
            boost::system::error_code error;
            socket.receive_from(boost::asio::buffer(recv_buf), remote_endpoint, 0, error);

            if (error && error != boost::asio::error::message_size)
                throw boost::system::system_error(error);

            std::string message = "Hello, world!";

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
