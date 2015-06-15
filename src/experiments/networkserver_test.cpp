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
        // Update values in packet
        server.get_n2m_standard_packet()->set_vel_x(server.get_n2m_standard_packet()->get_vel_x() + 1.0);
        server.get_n2m_standard_packet()->set_vel_y(server.get_n2m_standard_packet()->get_vel_y() + 2.0);
        server.get_n2m_standard_packet()->set_pos_z(server.get_n2m_standard_packet()->get_pos_z() + 3.0);
        server.get_n2m_standard_packet()->set_rot_x(server.get_n2m_standard_packet()->get_rot_x() + 4.0);
        server.get_n2m_standard_packet()->set_rot_y(server.get_n2m_standard_packet()->get_rot_y() + 5.0);
        server.get_n2m_standard_packet()->set_rot_z(server.get_n2m_standard_packet()->get_rot_z() + 6.0);

        // Print received packet
        std::cout << "===== RECEIVED PACKET =====" << std::endl;
        std::cout << "pos_z = " << server.get_m2n_standard_packet()->get_pos_z() << std::endl;
        std::cout << "orient_x = " << server.get_m2n_standard_packet()->get_orient_x() << std::endl;
        std::cout << "orient_y = " << server.get_m2n_standard_packet()->get_orient_y() << std::endl;
        std::cout << "orient_z = " << server.get_m2n_standard_packet()->get_orient_z() << std::endl;
        std::cout << "health = " << server.get_m2n_standard_packet()->get_health() << std::endl;
        std::cout << "bat_v = " << server.get_m2n_standard_packet()->get_bat_v() << std::endl;
        std::cout << "===========================" << std::endl;


        // Sleep for 10 ms
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
    
    return EXIT_SUCCESS;
}
