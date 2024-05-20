#include "Client.h"
#include <iostream>
#include <arpa/inet.h>
#include <unistd.h>
#include <thread>

int main() {
    int port = 8080; // Specify the port number
    std::string server_ip = "127.0.0.1"; // Specify the server IP address
    std::string username;

    // Prompt the user for their username
    std::cout << "Enter your username: ";
    std::getline(std::cin, username);

    // Create a socket
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd == -1) {
        std::cerr << "Error creating socket" << std::endl;
        return 1;
    }

    // Define the server address
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);
    if (inet_pton(AF_INET, server_ip.c_str(), &server_address.sin_addr) <= 0) {
        std::cerr << "Invalid address/Address not supported" << std::endl;
        close(socket_fd);
        return 1;
    }

    // Connect to the server
    if (connect(socket_fd, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
        std::cerr << "Connection failed" << std::endl;
        close(socket_fd);
        return 1;
    }

    // Send the username to the server
    send(socket_fd, username.c_str(), username.length(), 0);

    // Initialize Client object
    try {
        Client client(socket_fd, username);
        std::thread listenThread(&Client::listenForMessage, &client);
        client.sendMessage();
        listenThread.join();
    } catch (const std::exception& e) {
        std::cerr << "Client error: " << e.what() << std::endl;
        close(socket_fd);
        return 1;
    }

    return 0;
}
