#include <stdint.h>
#include <mutex>
#include <bitset>
#include <string.h>
#include <math.h>
#include "N2MStandardPacket.hpp"

N2MStandardPacket::N2MStandardPacket()
{
    std::lock_guard<std::mutex> packet_lock(packet_mtx);
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
    std::lock_guard<std::mutex> packet_lock(packet_mtx);
    return n2m_standard_packet.header;
}

void N2MStandardPacket::set_vel_x(double vel_x)
{
    int32_t vel_x_q = (int32_t)round(vel_x * pow(2, Q));
    std::lock_guard<std::mutex> packet_lock(packet_mtx);
    n2m_standard_packet.vel_x = vel_x_q;
}

double N2MStandardPacket::get_vel_x()
{
    std::lock_guard<std::mutex> packet_lock(packet_mtx);
    return ((double)n2m_standard_packet.vel_x) * pow(2, -Q);
}

void N2MStandardPacket::set_vel_y(double vel_y)
{
    int32_t vel_y_q = (int32_t)round(vel_y * pow(2, Q));
    std::lock_guard<std::mutex> packet_lock(packet_mtx);
    n2m_standard_packet.vel_y = vel_y_q;
}

double N2MStandardPacket::get_vel_y()
{
    std::lock_guard<std::mutex> packet_lock(packet_mtx);
    return ((double)n2m_standard_packet.vel_y) * pow(2, -Q);
}

void N2MStandardPacket::set_pos_z(double pos_z)
{
    uint32_t pos_z_q = (uint32_t)round(pos_z * pow(2, Q));
    std::lock_guard<std::mutex> packet_lock(packet_mtx);
    n2m_standard_packet.pos_z = pos_z_q;
}

double N2MStandardPacket::get_pos_z()
{
    std::lock_guard<std::mutex> packet_lock(packet_mtx);
    return ((double)n2m_standard_packet.pos_z) * pow(2, -Q);
}

void N2MStandardPacket::set_rot_x(double rot_x)
{
    int32_t rot_x_q = (int32_t)round(rot_x * pow(2, Q));
    std::lock_guard<std::mutex> packet_lock(packet_mtx);
    n2m_standard_packet.vel_x = rot_x_q;
}

double N2MStandardPacket::get_rot_x()
{
    std::lock_guard<std::mutex> packet_lock(packet_mtx);
    return ((double)n2m_standard_packet.rot_x) * pow(2, -Q);
}

void N2MStandardPacket::set_rot_y(double rot_y)
{
    int32_t rot_y_q = (int32_t)round(rot_y * pow(2, Q));
    std::lock_guard<std::mutex> packet_lock(packet_mtx);
    n2m_standard_packet.rot_y = rot_y_q;
}

double N2MStandardPacket::get_rot_y()
{
    std::lock_guard<std::mutex> packet_lock(packet_mtx);
    return ((double)n2m_standard_packet.rot_y) * pow(2, -Q);
}

void N2MStandardPacket::set_rot_z(double rot_z)
{
    int32_t rot_z_q = (int32_t)round(rot_z * pow(2, Q));
    std::lock_guard<std::mutex> packet_lock(packet_mtx);
    n2m_standard_packet.rot_z = rot_z_q;
}

double N2MStandardPacket::get_rot_z()
{
    std::lock_guard<std::mutex> packet_lock(packet_mtx);
    return ((double)n2m_standard_packet.rot_z) * pow(2, -Q);
}

size_t N2MStandardPacket::size() const
{
    return n2m_standard_packet_size;
}

void N2MStandardPacket::read_buffer(unsigned char buffer[])
{
    std::lock_guard<std::mutex> packet_lock(packet_mtx);
    n2m_standard_packet_t old_n2m_standard_packet = n2m_standard_packet;
    memcpy(&n2m_standard_packet, buffer, n2m_standard_packet_size);
    n2m_standard_packet = old_n2m_standard_packet;
}

void N2MStandardPacket::get_buffer(unsigned char buffer[])
{
    std::lock_guard<std::mutex> packet_lock(packet_mtx);
    memcpy(buffer, &n2m_standard_packet, n2m_standard_packet_size);
}
