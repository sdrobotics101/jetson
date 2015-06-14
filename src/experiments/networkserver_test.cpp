#include <iostream>
#include <chrono>

#include "NetworkServer.hpp"
#include "N2MStandardPacket.hpp"
#include "M2NStandardPacket.hpp"

int main(int argc, char* argv[])
{
    NetworkServer server;
    server.open();
    server.start();
    for (;;)
    {
        server.get_n2m_standard_packet()->set_vel_x(server.get_n2m_standard_packet()->get_vel_x() + 1.0);
        server.get_n2m_standard_packet()->set_vel_y(server.get_n2m_standard_packet()->get_vel_y() + 2.0);
        server.get_n2m_standard_packet()->set_pos_z(server.get_n2m_standard_packet()->get_pos_z() + 3.0);
        server.get_n2m_standard_packet()->set_rot_x(server.get_n2m_standard_packet()->get_rot_x() + 4.0);
        server.get_n2m_standard_packet()->set_rot_y(server.get_n2m_standard_packet()->get_rot_y() + 5.0);
        server.get_n2m_standard_packet()->set_rot_z(server.get_n2m_standard_packet()->get_rot_z() + 6.0);
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
    
    return EXIT_SUCCESS;
}
