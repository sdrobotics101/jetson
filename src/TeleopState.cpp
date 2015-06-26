#include <iostream>
#include "TeleopState.hpp"

TeleopState::TeleopState()
{
    first_run = true;
}

void TeleopState::update()
{
    if (first_run)
    {
        first_run = false;
        std::cout << "Cubeception 2.0 Helm" << std::endl;
        std::cout << "Type \"help\" for help with commands" << std::endl << std::endl;
    }
    std::cout << "TeleopState::update()" << std::endl;
}
