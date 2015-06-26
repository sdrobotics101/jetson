find_package(OpenCV REQUIRED)
add_executable(robosub_jetson robosub_jetson.cpp BaseVideoDevice.cpp CLIOptions.cpp M2NStandardPacket.cpp N2MStandardPacket.cpp NetworkServer.cpp PausedState.cpp Robot.cpp RobotState.cpp TeleopState.cpp USBVideoDevice.cpp)
target_link_libraries(robosub_jetson ${OpenCV_LIBS})
add_subdirectory(experiments)
