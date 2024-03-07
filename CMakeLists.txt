# CMakeLists.txt

cmake_minimum_required(VERSION 3.10)
project(FileAndTCP_ChannelsForTrace)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add client executable
add_executable(client
    client/client.cpp
    client/TraceLogger.cpp  # Add TraceLogger.cpp here
)

# Add server executable
add_executable(server
    server/server.cpp
)

# Include directories
target_include_directories(client PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/client)
target_include_directories(server PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/server)
