# ChatApp

## Overview

ChatApp is a simple client-server chat application implemented in C++. It allows multiple clients to connect to a server and communicate with each other in real time. The application is designed with a focus on simplicity and clarity, making it easy to understand and extend.

## Project Structure

The project is organized into several components, each responsible for different aspects of the chat application:

- **Client**: Manages the user's connection and communication with the server.
- **ClientHandler**: Manages individual client connections on the server side.
- **Server**: Manages incoming client connections and oversees overall server operations.

### Directory Structure

ChatApp/
├── include/
│ ├── Client.h
│ ├── ClientHandler.h
│ └── Server.h
├── src/
│ ├── Client.cpp
│ ├── ClientHandler.cpp
│ ├── ClientMain.cpp
│ ├── Server.cpp
│ └── ServerMain.cpp
└── CMakeLists.txt


## Components

### 1. Client

The `Client` class is responsible for handling the client's connection to the server. It manages sending and receiving messages and ensures the connection is properly closed when the client exits.

**Key Methods:**
- `sendMessage()`: Allows the client to send messages to the server.
- `listenForMessage()`: Listens for incoming messages from the server and displays them to the user.
- `closeEverything()`: Closes all open resources (socket and file descriptors).

### 2. ClientHandler

The `ClientHandler` class manages individual client connections on the server side. It is responsible for reading messages from a client and broadcasting them to all other connected clients.

**Key Methods:**
- `run()`: Main loop to handle incoming messages from the client.
- `broadcastMessage()`: Sends a message to all connected clients.
- `closeEverything()`: Closes the client's connection and cleans up resources.
- `removeClientHandler()`: Removes the client handler from the active handlers list and notifies other clients of the disconnection.

### 3. Server

The `Server` class initializes the server socket, accepts incoming client connections, and creates a `ClientHandler` for each connected client. It runs in a loop, continuously accepting new clients.

**Key Methods:**
- `startServer()`: Starts the server and handles incoming client connections.

## Building and Running

### Prerequisites

- C++11 compatible compiler
- CMake 3.10 or higher

### Building

1. **Generate build files with CMake:**
   ```sh
   cmake -B build
