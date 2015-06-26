#ifndef PausedState_hpp
#define PausedState_hpp

#include "RobotState.hpp"

class PausedState : public RobotState {
public:
    virtual void update();
};

#endif // PausedState_hpp
