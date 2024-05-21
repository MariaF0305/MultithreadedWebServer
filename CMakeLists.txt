cmake_minimum_required(VERSION 3.10)
project(ChatApp)

set(CMAKE_CXX_STANDARD 11)

# Include directories
include_directories(include)

# Add source files
set(CLIENT_SOURCE_FILES
    src/Client.cpp
    src/ClientMain.cpp
)

set(SERVER_SOURCE_FILES
    src/ClientHandler.cpp
    src/Server.cpp
    src/ServerMain.cpp
)

# Add header files
set(HEADER_FILES
    include/Client.h
    include/ClientHandler.h
    include/Server.h
)

# Add executables
add_executable(ChatClient ${CLIENT_SOURCE_FILES})
add_executable(ChatServer ${SERVER_SOURCE_FILES})
