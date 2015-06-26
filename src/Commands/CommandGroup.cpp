#include <vector>
#include "Command.hpp"
#include "CommandGroup.hpp"

CommandGroup::CommandGroup()
{
}

void CommandGroup::run()
{
    for (Command *command : commands)
    {
        command->run();
        delete command;
    }
}

void CommandGroup::add_command(Command *command)
{
    commands.push_back(command);
}
