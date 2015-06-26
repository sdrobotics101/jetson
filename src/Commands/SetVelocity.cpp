#include "../Robot.hpp"
#include "SetVelocity.hpp"

SetVelocity::SetVelocity(double vel_x, double vel_y)
{
    this->vel_x = vel_x;
    this->vel_y = vel_y;
}

void SetVelocity::run()
{
    Robot::get_instance()->get_microzed()->get_n2m_standard_packet()->set_vel_x(vel_x);
    Robot::get_instance()->get_microzed()->get_n2m_standard_packet()->set_vel_y(vel_y);
}
