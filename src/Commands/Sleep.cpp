#include <thread>
#include <chrono>
#include "Sleep.hpp"

Sleep::Sleep(int milliseconds)
{
    this->milliseconds = milliseconds;
}

void Sleep::run()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}
