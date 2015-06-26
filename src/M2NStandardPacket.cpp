#include <stdint.h>
#include <mutex>
#include <bitset>
#include <string.h>
#include <math.h>
#include "M2NStandardPacket.hpp"

M2NStandardPacket::M2NStandardPacket()
{
    std::lock_guard<std::mutex> packet_lock(packet_mtx);
    m2n_standard_packet.header = 0;
    m2n_standard_packet.pos_z = 0;
    m2n_standard_packet.orient_x = 0;
    m2n_standard_packet.orient_y = 0;
    m2n_standard_packet.orient_z = 0;
    m2n_standard_packet.health = 0;
    m2n_standard_packet.bat_v = 0;
}

uint32_t M2NStandardPacket::get_header()
{
    std::lock_guard<std::mutex> packet_lock(packet_mtx);
    return m2n_standard_packet.header;
}

void M2NStandardPacket::set_pos_z(double pos_z)
{
    int32_t pos_z_q = (int32_t)round(pos_z * pow(2, Q));
    std::lock_guard<std::mutex> packet_lock(packet_mtx);
    m2n_standard_packet.pos_z = pos_z_q;
}

double M2NStandardPacket::get_pos_z()
{
    std::lock_guard<std::mutex> packet_lock(packet_mtx);
    return ((double)m2n_standard_packet.pos_z) * pow(2, -Q);
}

void M2NStandardPacket::set_orient_x(double orient_x)
{
    int32_t orient_x_q = (int32_t)round(orient_x * pow(2, Q));
    std::lock_guard<std::mutex> packet_lock(packet_mtx);
    m2n_standard_packet.orient_x = orient_x_q;
}

double M2NStandardPacket::get_orient_x()
{
    std::lock_guard<std::mutex> packet_lock(packet_mtx);
    return ((double)m2n_standard_packet.orient_x) * pow(2, -Q);
}

void M2NStandardPacket::set_orient_y(double orient_y)
{
    uint32_t orient_y_q = (uint32_t)round(orient_y * pow(2, Q));
    std::lock_guard<std::mutex> packet_lock(packet_mtx);
    m2n_standard_packet.orient_y = orient_y_q;
}

double M2NStandardPacket::get_orient_y()
{
    std::lock_guard<std::mutex> packet_lock(packet_mtx);
    return ((double)m2n_standard_packet.orient_y) * pow(2, -Q);
}

void M2NStandardPacket::set_orient_z(double orient_z)
{
    int32_t orient_z_q = (int32_t)round(orient_z * pow(2, Q));
    std::lock_guard<std::mutex> packet_lock(packet_mtx);
    m2n_standard_packet.orient_z = orient_z_q;
}

double M2NStandardPacket::get_orient_z()
{
    std::lock_guard<std::mutex> packet_lock(packet_mtx);
    return ((double)m2n_standard_packet.orient_z) * pow(2, -Q);
}

void M2NStandardPacket::set_health(double health)
{
    int32_t health_q = (int32_t)round(health * pow(2, Q));
    std::lock_guard<std::mutex> packet_lock(packet_mtx);
    m2n_standard_packet.health = health_q;
}

double M2NStandardPacket::get_health()
{
    std::lock_guard<std::mutex> packet_lock(packet_mtx);
    return ((double)m2n_standard_packet.health) * pow(2, -Q);
}

void M2NStandardPacket::set_bat_v(double bat_v)
{
    int32_t bat_v_q = (int32_t)round(bat_v * pow(2, Q));
    std::lock_guard<std::mutex> packet_lock(packet_mtx);
    m2n_standard_packet.bat_v = bat_v_q;
}

double M2NStandardPacket::get_bat_v()
{
    std::lock_guard<std::mutex> packet_lock(packet_mtx);
    return ((double)m2n_standard_packet.bat_v) * pow(2, -Q);
}

size_t M2NStandardPacket::size() const
{
    return m2n_standard_packet_size;
}

void M2NStandardPacket::read_buffer(unsigned char buffer[])
{
    std::lock_guard<std::mutex> packet_lock(packet_mtx);
    memcpy(&m2n_standard_packet, buffer, m2n_standard_packet_size);
}

void M2NStandardPacket::get_buffer(unsigned char buffer[])
{
    std::lock_guard<std::mutex> packet_lock(packet_mtx);
    memcpy(buffer, &m2n_standard_packet, m2n_standard_packet_size);
}
