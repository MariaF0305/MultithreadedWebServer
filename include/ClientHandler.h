#ifndef CLIENT_HANDLER_H
#define CLIENT_HANDLER_H

#include <string>
#include <cstdio>
#include <vector>

class ClientHandler {
private:
    int socket_fd;
    FILE* file_read;
    FILE* file_write;
    std::string clientInfo;
    std::string clientUsername;

    void closeEverything();
    void removeClientHandler();
    void broadcastMessage(const std::string& messageToSend);

    static std::vector<ClientHandler*> clientHandlers;

public:
    ClientHandler(int socket_fd, const std::string& clientInfo);
    ~ClientHandler();
    void run();
};

#endif // CLIENT_HANDLER_H
