#include <cmath>
#include <Eigen/Dense>
#include "../Robot.hpp"
#include "SetVelocity.hpp"

SetVelocity::SetVelocity(double vel_x, double vel_y)
{
    this->vel_x = vel_x;
    this->vel_y = vel_y;
}

void SetVelocity::run()
{
    Eigen::Vector2d vel(vel_x, vel_y);
    double theta = Robot::get_instance()->get_microzed()->get_m2n_standard_packet()->get_orient_z() * M_PI / 180.0;
    Eigen::Matrix2d rotation_mat;
    rotation_mat << cos(theta), -sin(theta),
                    sin(theta), cos(theta);
    Eigen::Vector2d vel_prime = rotation_mat * vel;
    Robot::get_instance()->get_microzed()->get_n2m_standard_packet()->set_vel_x(vel_prime(0));
    Robot::get_instance()->get_microzed()->get_n2m_standard_packet()->set_vel_y(vel_prime(1));
}
