#include "Server.h"
#include "ClientHandler.h"
#include <stdexcept>
#include <iostream>
#include <thread>
#include <arpa/inet.h>
#include <unistd.h>

Server::Server(int port) {
    server_socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket_fd == -1)
        throw std::runtime_error("Error creating server socket");

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(port);

    if (bind(server_socket_fd, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
        close(server_socket_fd);
        throw std::runtime_error("Error binding server socket");
    }

    if (listen(server_socket_fd, 3) < 0) {
        close(server_socket_fd);
        throw std::runtime_error("Error listening on server socket");
    }
}

Server::~Server() {
    close(server_socket_fd);
}

void Server::startServer() {
    while (true) {
        struct sockaddr_in client_address;
        socklen_t client_address_len = sizeof(client_address);
        int client_socket_fd = accept(server_socket_fd, (struct sockaddr*)&client_address, &client_address_len);
        if (client_socket_fd < 0)
            continue;

        // Read the client's IP and port
        char clientInfo[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &(client_address.sin_addr), clientInfo, INET_ADDRSTRLEN);
        int client_port = ntohs(client_address.sin_port);
        std::string client_info_str = std::string(clientInfo) + ":" + std::to_string(client_port);

        // Log that a new client connected
        std::cout << "A new client connected: " << client_info_str << std::endl;

        // Create a new ClientHandler for each connected client
        ClientHandler* clientHandler = new ClientHandler(client_socket_fd, client_info_str);
        std::thread t(&ClientHandler::run, clientHandler);
        t.detach(); // Detach the thread to allow independent execution
    }
}
