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
    std::cout << "theta = " << theta * 180.0 / M_PI << std::endl;
    Eigen::Matrix2d rotation_mat;
    rotation_mat << cos(theta), -sin(theta),
                    sin(theta), cos(theta);
    std::cout << "rotation_mat = " << std::endl << rotation_mat << std::endl;
    Eigen::Vector2d vel_prime = rotation_mat * vel;
    std::cout << "vel_prime = " << std::endl << vel_prime << std::endl;
    Robot::get_instance()->get_microzed()->get_n2m_standard_packet()->set_vel_x(vel_prime(0));
    Robot::get_instance()->get_microzed()->get_n2m_standard_packet()->set_vel_y(vel_prime(1));
}
