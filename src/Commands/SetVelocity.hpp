#ifndef SetVelocity_hpp
#define SetVelocity_hpp

#include "Command.hpp"

class SetVelocity : public Command
{
public:
    SetVelocity(double vel_x, double vel_y);
    void run();
private:
    double vel_x;
    double vel_y;
};

#endif // SetVelocity_hpp
