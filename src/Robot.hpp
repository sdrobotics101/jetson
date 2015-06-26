#ifndef Robot_hpp
#define Robot_hpp

#include <cstdlib>
#include <string>
#include "BaseVideoDevice.hpp"
#include "Networking/NetworkServer.hpp"
#include "RobotState.hpp"

class Robot {
public:
    Robot(RobotState *state);
    ~Robot();
    static Robot *get_instance();
    void start();
    void set_state(RobotState *state);
    void set_period(int new_period);
    BaseVideoDevice *get_forward_camera();
    NetworkServer *get_microzed();
private:
    static Robot *instance;
    NetworkServer microzed;
    BaseVideoDevice *forward_camera;
    RobotState *state;
    int period; // ms
};

#endif // Robot_hpp
