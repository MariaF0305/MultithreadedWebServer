#include "Server.h"
#include <iostream>

int main() {
    int port = 8080; // Specify the port number
    
    try {
        Server server(port);
        server.startServer();
    } catch (const std::exception& e) {
        std::cerr << "Server error: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}
