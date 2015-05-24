#ifndef N2MStandardPacket_hpp
#define N2MStandardPacket_hpp

#include <stdint.h>
#include <mutex>
#include <bitset>

class N2MStandardPacket {
public:
    N2MStandardPacket();
    uint32_t get_header();
    void set_vel_x(double vel_x);
    double get_vel_x();
    size_t size() const;
    void read_buffer(unsigned char buffer[]);
    void get_buffer(unsigned char buffer[]);
private:
    typedef struct {
        uint32_t header;
        int32_t vel_x;
        int32_t vel_y;
        uint32_t pos_z;
        int32_t rot_x;
        int32_t rot_y;
        int32_t rot_z;
        uint32_t mode;
    } __attribute__ ((__packed__)) n2m_standard_packet_t;
    n2m_standard_packet_t n2m_standard_packet;
    std::mutex n2m_standard_packet_mtx;
    const size_t n2m_standard_packet_size = sizeof(n2m_standard_packet_t);
    const int Q = 16;
};

#endif // N2MStandardPacket_hpp
