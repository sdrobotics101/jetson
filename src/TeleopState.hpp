#ifndef TeleopState_hpp
#define TeleopState_hpp

#include "RobotState.hpp"

class TeleopState : public RobotState {
public:
    virtual void update();
protected:
    void teleop_periodic();
};
#endif // TeleopState_hpp
