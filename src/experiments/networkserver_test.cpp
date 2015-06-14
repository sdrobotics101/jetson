#include <iostream>

#include "NetworkServer.hpp"
#include "N2MStandardPacket.hpp"
#include "M2NStandardPacket.hpp"

int main(int argc, char* argv[])
{
    NetworkServer server;
    server.open();
    server.start();
    server.get_n2m_standard_packet()->set_vel_x(123.45);
    while (1);
    
    return EXIT_SUCCESS;
}
