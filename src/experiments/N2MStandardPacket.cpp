#include <stdint.h>
#include <mutex>
#include <bitset>
#include <string.h>
#include <math.h>
#include "N2MStandardPacket.hpp"

N2MStandardPacket::N2MStandardPacket()
{
    std::lock_guard<std::mutex> n2m_standard_packet_lock(n2m_standard_packet_mtx);
    n2m_standard_packet.header = 0;
    n2m_standard_packet.vel_x = 0;
    n2m_standard_packet.vel_y = 0;
    n2m_standard_packet.pos_z = 0;
    n2m_standard_packet.rot_x = 0;
    n2m_standard_packet.rot_y = 0;
    n2m_standard_packet.rot_z = 0;
    n2m_standard_packet.mode = 0;
}

uint32_t N2MStandardPacket::get_header()
{
    std::lock_guard<std::mutex> n2m_standard_packet_lock(n2m_standard_packet_mtx);
    return n2m_standard_packet.header;
}

void N2MStandardPacket::set_vel_x(double vel_x)
{
    int32_t vel_x_q = (int32_t)round(vel_x * pow(2, Q));
    std::lock_guard<std::mutex> n2m_standard_packet_lock(n2m_standard_packet_mtx);
    n2m_standard_packet.vel_x = vel_x_q;
}

double N2MStandardPacket::get_vel_x()
{
    std::lock_guard<std::mutex> n2m_standard_packet_lock(n2m_standard_packet_mtx);
    return ((double)n2m_standard_packet.vel_x) * pow(2, -Q);
}

size_t N2MStandardPacket::size() const
{
    return n2m_standard_packet_size;
}

void N2MStandardPacket::read_buffer(unsigned char buffer[])
{
    std::lock_guard<std::mutex> n2m_standard_packet_lock(n2m_standard_packet_mtx);
    n2m_standard_packet_t old_n2m_standard_packet = n2m_standard_packet;
    memcpy(&n2m_standard_packet, buffer, n2m_standard_packet_size);
    n2m_standard_packet = old_n2m_standard_packet;
}

void N2MStandardPacket::get_buffer(unsigned char buffer[])
{
    std::lock_guard<std::mutex> n2m_standard_packet_lock(n2m_standard_packet_mtx);
    memcpy(buffer, &n2m_standard_packet, n2m_standard_packet_size);
}
