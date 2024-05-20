#ifndef SERVER_H
#define SERVER_H

class Server {
private:
    int server_socket_fd;

public:
    Server(int port);
    ~Server();
    void startServer();
};

#endif // SERVER_H
