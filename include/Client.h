#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include <cstdio>

class Client {
private:
    int socket_fd;
    FILE* file_read;
    FILE* file_write;
    std::string username;

public:
    Client(int socket_fd, const std::string& username);
    ~Client();
    void sendMessage();
    void listenForMessage();
    void closeEverything();
};

#endif // CLIENT_H
