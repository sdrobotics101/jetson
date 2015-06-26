#include <cstdlib>
#include <thread>
#include <chrono>
#include "RobotState.hpp"
#include "PausedState.hpp"
#include "BaseVideoDevice.hpp"
#include "USBVideoDevice.hpp"
#include "Networking/NetworkServer.hpp"
#include "Robot.hpp"

Robot* Robot::instance = NULL;

Robot::Robot(RobotState* state)
{
    period = 10; // ms
    set_state(state);
    microzed.open();
    microzed.start();
    //forward_camera = new USBVideoDevice(0);
    //forward_camera->start();
}

Robot::~Robot()
{
    delete forward_camera;
    delete state;
}

Robot *Robot::get_instance()
{
    if (!instance)
        instance = new Robot(new PausedState());
    return instance;
}

void Robot::start()
{
    while (true)
    {
        state->update();
        std::this_thread::sleep_for(std::chrono::milliseconds(period));
    }
}

void Robot::set_state(RobotState *state)
{
    this->state = state;
}

void Robot::set_period(int new_period)
{
    period = new_period;
}

BaseVideoDevice *Robot::get_forward_camera()
{
    return forward_camera;
}

NetworkServer *Robot::get_microzed()
{
    return &microzed;
}
