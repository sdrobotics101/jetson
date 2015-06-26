#ifndef Command_hpp
#define Command_hpp

class Command
{
public:
    virtual ~Command();
    virtual void run() = 0;
protected:
};

#endif // Command_hpp
