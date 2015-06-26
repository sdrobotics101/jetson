#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <bitset>
#include "Robot.hpp"
#include "TeleopState.hpp"

TeleopState::TeleopState()
{
    robot = Robot::get_instance();
    first_run = true;
    bat_v_threshold = 6.0; // V
    num_base = NumberBase::dec;
}

void TeleopState::update()
{
    if (first_run)
    {
        first_run = false;
        teleop_init();
    }
    teleop_periodic();
}

void TeleopState::teleop_init()
{
    std::cout << "Cubeception 2.0 Helm" << std::endl;
    std::cout << "Type \"help\" for help with commands" << std::endl << std::endl;
}

void TeleopState::teleop_periodic()
{
    if (robot->get_microzed()->get_m2n_standard_packet()->get_bat_v() < bat_v_threshold)
        std::cout << std::endl << "WARNING: LOW BATTERY VOLTAGE: " << robot->get_microzed()->get_m2n_standard_packet()->get_bat_v() << " V" << std::endl;
    std::cout << "cubeception> ";
    std::string input;
    std::getline(std::cin, input);
    if (input.find(" ") == std::string::npos)
    {
        if (input == "pos_z")
            std::cout << "pos_z = " << robot->get_microzed()->get_m2n_standard_packet()->get_pos_z() << std::endl;
        else if (input == "orient_x")
            std::cout << "orient_x = " << robot->get_microzed()->get_m2n_standard_packet()->get_orient_x() << std::endl;
        else if (input == "orient_y")
            std::cout << "orient_y = " << robot->get_microzed()->get_m2n_standard_packet()->get_orient_y() << std::endl;
        else if (input == "orient_z")
            std::cout << "orient_x = " << robot->get_microzed()->get_m2n_standard_packet()->get_orient_z() << std::endl;
        else if (input == "health")
            std::cout << "health = " << robot->get_microzed()->get_m2n_standard_packet()->get_health() << std::endl;
        else if (input == "bat_v")
            std::cout << "bat_v = " << robot->get_microzed()->get_m2n_standard_packet()->get_bat_v() << std::endl;
        else if (input == "dec")
        {
            std::cin >> std::dec;
            std::cout << std::dec;
            num_base = NumberBase::dec;
            std::cout << "Set base to decimal" << std::endl;
        }
        else if (input == "hex")
        {
            std::cin >> std::hex;
            std::cout << std::hex;
            num_base = NumberBase::hex;
            std::cout << "Set base to hex" << std::endl;
        }
        else if (input == "oct")
        {
            std::cin >> std::oct;
            std::cout << std::oct;
            num_base = NumberBase::oct;
            std::cout << "Set base to octal" << std::endl;
        }
        else if (input == "exit")
        {
            std::exit(0);
        }
        else if (input == "help")
        {
            std::cout << "Available commands:" << std::endl << std::endl;
            std::cout << std::right << std::setw(14) << "vel_x  "
                      << std::left << std::setw(8) << "double"
                      << std::setw(0) << "set linear velocity along x-axis" << std::endl;
        }
        else
            std::cout << input << ": command not found" << std::endl;
    }
    else
    {
        std::string key;
        double value;
        if (num_base == NumberBase::dec)
            std::istringstream(input) >> std::hex >> key >> value;
        else if (num_base == NumberBase::hex)
            std::istringstream(input) >> std::hex >> key >> value;
        else if (num_base == NumberBase::oct)
            std::istringstream(input) >> std::oct >> key >> value;
        if (key == "vel_x")
        {
            robot->get_microzed()->get_n2m_standard_packet()->set_vel_x(value);
            std::cout << "Set vel_x = " << value << std::endl;
        }
        else
            std::cout << key << ": command not found" << std::endl;
    }
}
