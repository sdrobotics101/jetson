#ifndef TeleopState_hpp
#define TeleopState_hpp

#include "Robot.hpp"
#include "RobotState.hpp"

class TeleopState : public RobotState {
public:
    TeleopState();
    virtual void update();
protected:
    void teleop_init();
    void teleop_periodic();
    bool first_run;
    Robot *robot;
    enum class NumberBase { dec, hex, oct };
    NumberBase num_base;
    double bat_v_threshold;
};
#endif // TeleopState_hpp
