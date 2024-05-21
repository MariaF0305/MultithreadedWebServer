#include "ClientHandler.h"
#include <stdexcept>
#include <iostream>
#include <unistd.h>
#include <sys/socket.h>

std::vector<ClientHandler*> ClientHandler::clientHandlers;

ClientHandler::ClientHandler(int socket_fd, const std::string& clientInfo) : socket_fd(socket_fd), clientInfo(clientInfo) {
    file_read = fdopen(socket_fd, "r");
    file_write = fdopen(socket_fd, "w");
    if (file_read == nullptr || file_write == nullptr) {
        closeEverything();
        throw std::runtime_error("Error opening socket file descriptors");
    }

    // Read the username sent by the client
    char buffer[1024] = {0};
    if (recv(socket_fd, buffer, sizeof(buffer), 0) <= 0) {
        closeEverything();
        throw std::runtime_error("Error reading client username");
    }
    clientUsername = std::string(buffer);
    clientUsername.erase(clientUsername.find_last_not_of(" \n\r\t") + 1); // Trim newline characters
    clientHandlers.push_back(this);
    std::cout << "Client username: " << clientUsername << " has connected." << std::endl;
}

ClientHandler::~ClientHandler() {
    closeEverything();
}

void ClientHandler::closeEverything() {
    if (file_read != nullptr)
        fclose(file_read);
    if (file_write != nullptr)
        fclose(file_write);
    if (socket_fd != -1)
        ::close(socket_fd); // Use ::close() to close socket file descriptor
    removeClientHandler();
}

void ClientHandler::run() {
    while (true) {
        char buffer[1024] = {0};
        if (fgets(buffer, sizeof(buffer), file_read) == nullptr)
            break;
        std::cout << "Message (" << clientUsername << "): " << buffer;
        broadcastMessage("Message (" + clientUsername + "): " + buffer);
    }
    removeClientHandler();
}

void ClientHandler::broadcastMessage(const std::string& messageToSend) {
    for (ClientHandler* clientHandler : clientHandlers) {
        fprintf(clientHandler->file_write, "%s", messageToSend.c_str());
        fflush(clientHandler->file_write);
    }
}

void ClientHandler::removeClientHandler() {
    std::string leavingMessage = clientUsername + " has left the chat\n";
    broadcastMessage(leavingMessage);

    for (auto it = clientHandlers.begin(); it != clientHandlers.end(); ++it) {
        if (*it == this) {
            clientHandlers.erase(it);
            break;
        }
    }

    // Additional logic to handle server shutdown
    if (clientHandlers.empty()) {
        // Send a server shutdown message to all clients
        std::string serverShutdownMessage = "Server has shut down\n";
        broadcastMessage(serverShutdownMessage);
    }
}


