#ifndef M2NStandardPacket_hpp
#define M2NStandardPacket_hpp

#include <stdint.h>
#include <mutex>
#include <bitset>

#include "Packet.hpp"

class M2NStandardPacket : Packet {
public:
    M2NStandardPacket();
    uint32_t get_header();
    void set_pos_z(double pos_z);
    double get_pos_z();
    void set_orient_x(double orient_x);
    double get_orient_x();
    void set_orient_y(double orient_y);
    double get_orient_y();
    void set_orient_z(double orient_z);
    double get_orient_z();
    void set_health(double health);
    double get_health();
    void set_bat_v(double bat_v);
    double get_bat_v();
    size_t size() const;
    void read_buffer(unsigned char buffer[]);
    void get_buffer(unsigned char buffer[]);
protected:
    typedef struct {
        uint32_t header;
        uint32_t pos_z;
        int32_t orient_x;
        int32_t orient_y;
        int32_t orient_z;
        uint32_t health;
        int32_t bat_v;
    } __attribute__ ((__packed__)) m2n_standard_packet_t;
    m2n_standard_packet_t m2n_standard_packet;
    const size_t m2n_standard_packet_size = sizeof(m2n_standard_packet_t);
    const int Q = 16;
};

#endif // M2NStandardPacket_hpp
