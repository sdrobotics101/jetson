#ifndef CommandGroup_hpp
#define CommandGroup_hpp

#include <vector>
#include "Command.hpp"

class CommandGroup
{
public:
    CommandGroup();
protected:
    void run();
    void add_sequential(Command *command);
private:
    std::vector<Command*> commands;
};

#endif // CommandGroup_hpp
