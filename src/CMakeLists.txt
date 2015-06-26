find_package(OpenCV REQUIRED)
set(ROBOSUB_JETSON_SOURCE
    AutonomousState.cpp
    BaseVideoDevice.cpp
    CLIOptions.cpp
    PausedState.cpp
    robosub_jetson.cpp
    Robot.cpp
    RobotState.cpp
    TeleopState.cpp
    USBVideoDevice.cpp
   )
set(ROBOSUB_JETSON_HEADERS
    AutonomousState.hpp
    BaseVideoDevice.hpp
    CLIOptions.hpp
    PausedState.hpp
    Robot.hpp
    RobotState.hpp
    TeleopState.hpp
    USBVideoDevice.hpp
   )
add_subdirectory(Commands)
add_subdirectory(Networking)
add_subdirectory(CV)
add_executable(robosub_jetson ${ROBOSUB_JETSON_SOURCE} ${ROBOSUB_JETSON_HEADERS})
target_link_libraries(robosub_jetson ${OpenCV_LIBS})
add_subdirectory(experiments)
