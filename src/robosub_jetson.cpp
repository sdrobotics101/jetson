#include <cstdlib>
#include <iostream>
#include "CLIOptions.hpp"
#include "TeleopState.hpp"
#include "Robot.hpp"

int main(int argc, char* argv[])
{
    CLIOptions opts = CLIOptions(argc, argv);
    if (opts.is_interactive())
        Robot::get_instance()->set_state(new TeleopState());
    Robot::get_instance()->start();
    return EXIT_SUCCESS;
}
