#ifndef Sleep_hpp
#define Sleep_hpp

#include "Command.hpp"

class Sleep : public Command
{
public:
    Sleep(int milliseconds);
    void run();
private:
    int milliseconds;
};

#endif // Sleep_hpp
