#include "Client.h"
#include <stdexcept>
#include <iostream>
#include <unistd.h>

Client::Client(int socket_fd, const std::string& username) : socket_fd(socket_fd), username(username) {
    file_read = fdopen(socket_fd, "r");
    file_write = fdopen(socket_fd, "w");
    if (file_read == nullptr || file_write == nullptr) {
        closeEverything();
        throw std::runtime_error("Error opening socket file descriptors");
    }
}

Client::~Client() {
    closeEverything();
}

void Client::sendMessage() {
    std::string messageToSend;
    while (true) {
        std::getline(std::cin, messageToSend);
        if (messageToSend == "quit")
            break;
        fprintf(file_write, "%s: %s\n", username.c_str(), messageToSend.c_str());
        fflush(file_write);
    }
}

void Client::listenForMessage() {
    while (true) {
        char buffer[1024] = {0};
        if (fgets(buffer, sizeof(buffer), file_read) == nullptr)
            break;
        std::cout << buffer;
    }
}

void Client::closeEverything() {
    if (file_read != nullptr)
        fclose(file_read);
    if (file_write != nullptr)
        fclose(file_write);
    if (socket_fd != -1)
        close(socket_fd);
}
