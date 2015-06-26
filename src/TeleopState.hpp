#ifndef TeleopState_hpp
#define TeleopState_hpp

#include "RobotState.hpp"

class TeleopState : public RobotState {
public:
    TeleopState();
    virtual void update();
protected:
    void teleop_periodic();
    bool first_run;
};
#endif // TeleopState_hpp
