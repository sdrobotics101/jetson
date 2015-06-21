find_package(OpenCV REQUIRED)
add_executable(server server.cpp)
add_executable(networkserver_test networkserver_test.cpp NetworkServer.cpp N2MStandardPacket.cpp M2NStandardPacket.cpp)
add_executable(networkclient_test networkclient_test.cpp NetworkClient.cpp N2MStandardPacket.cpp M2NStandardPacket.cpp)
