#include <iostream>
#include <chrono>

#include "NetworkClient.hpp"
#include "N2MStandardPacket.hpp"
#include "M2NStandardPacket.hpp"

int main(int argc, char* argv[])
{
    NetworkClient client;
    client.open();
    client.start();
    for (;;)
    {
        // Update values in packet
        client.get_m2n_standard_packet()->set_pos_z(client.get_m2n_standard_packet()->get_pos_z() + 1.0);
        client.get_m2n_standard_packet()->set_orient_x(client.get_m2n_standard_packet()->get_orient_x() + 2.0);
        client.get_m2n_standard_packet()->set_orient_y(client.get_m2n_standard_packet()->get_orient_y() + 3.0);
        client.get_m2n_standard_packet()->set_orient_z(client.get_m2n_standard_packet()->get_orient_z() + 4.0);
        client.get_m2n_standard_packet()->set_health(client.get_m2n_standard_packet()->get_health() + 5.0);
        client.get_m2n_standard_packet()->set_bat_v(client.get_m2n_standard_packet()->get_bat_v() + 6.0);

        // Print received packet
        std::cout << "===== RECEIVED PACKET =====" << std::endl;
        std::cout << "vel_x = " << client.get_n2m_standard_packet()->get_vel_x() << std::endl;
        std::cout << "vel_y = " << client.get_n2m_standard_packet()->get_vel_y() << std::endl;
        std::cout << "pos_z = " << client.get_n2m_standard_packet()->get_pos_z() << std::endl;
        std::cout << "rot_x = " << client.get_n2m_standard_packet()->get_rot_x() << std::endl;
        std::cout << "rot_y = " << client.get_n2m_standard_packet()->get_rot_y() << std::endl;
        std::cout << "rot_z = " << client.get_n2m_standard_packet()->get_rot_z() << std::endl;
        std::cout << "===========================" << std::endl;

        // Sleep for 10 ms
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
    
    return EXIT_SUCCESS;
}
