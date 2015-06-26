#ifndef RobotState_hpp
#define RobotState_hpp

class RobotState {
public:
    virtual ~RobotState();
    virtual void update() = 0;
protected:
};

#endif // RobotState_hpp
