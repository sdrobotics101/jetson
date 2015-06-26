#ifndef Packet_hpp
#define Packet_hpp

#include <mutex>

class Packet {
public:
    virtual uint32_t get_header() = 0;
    virtual size_t size() const = 0;
    virtual void read_buffer(unsigned char buffer[]) = 0;
    virtual void get_buffer(unsigned char buffer[]) = 0;
protected:
    std::mutex packet_mtx;
};

#endif // Packet_hpp
