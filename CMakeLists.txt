cmake_minimum_required(VERSION 3.10)
project(MyProject)

# Add server source files and create server library
add_library(server
    server/server.c
)

# Add client source files and create client executable
add_executable(client
    client/client.c
)

# Link server library to client executable
target_link_libraries(client PRIVATE server)
