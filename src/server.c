#include "server.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

sem_t x, y;
pthread_t writerthreads[100];
pthread_t readerthreads[100];
int readercount = 0;

void* reader(void* param) {
    sem_wait(&x);
    readercount++;

    if (readercount == 1)
    sem_wait(&y);

    sem_post(&x);

    printf("\n%d reader is inside", readercount);
 
    sleep(5);
 
    sem_wait(&x);
    readercount--;
 
    if (readercount == 0) {
        sem_post(&y);
    }
 
    sem_post(&x);
 
    printf("\n%d Reader is leaving", readercount + 1);
    pthread_exit(NULL);
}

void* writer(void* param) {
    printf("\nWriter is trying to enter");
 
    sem_wait(&y);
 
    printf("\nWriter has entered");
 
    sem_post(&y);
 
    printf("\nWriter is leaving");
    pthread_exit(NULL);
}

void* handleClient(void* param) {
    int* socketPtr = (int*)param;
    int newSocket = *socketPtr;
    int choice = 0;
    recv(newSocket, &choice, sizeof(choice), 0);
 
    if (choice == 1) {
        if (pthread_create(&readerthreads[readercount++], NULL,
                           reader, &newSocket) != 0)
            printf("Failed to create thread\n");
    }
    else if (choice == 2) {
        if (pthread_create(&writerthreads[readercount++], NULL,
                           writer, &newSocket) != 0)
            printf("Failed to create thread\n");
    }
 
    if (readercount >= 50) {
        readercount = 0;
 
        while (readercount < 50) {
            pthread_join(writerthreads[readercount], NULL);
            pthread_join(readerthreads[readercount], NULL);
            readercount++;
        }
    }
    close(newSocket);
    pthread_exit(NULL);
}

void startServer() {
    int serverSocket, newSocket;
    struct sockaddr_in serverAddr, clientAddr;
    socklen_t addrSize;

    sem_init(&x, 0, 1);
    sem_init(&y, 0, 1);

    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(8989);
 
    bind(serverSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
 
    listen(serverSocket, 50);
 
    while (1) {
        addrSize = sizeof(clientAddr);
 
        newSocket = accept(serverSocket, (struct sockaddr*)&clientAddr, &addrSize);
 
        pthread_t tid;
        pthread_create(&tid, NULL, handleClient, &newSocket);
    }
}

int main() {
    // Server main function implementation
}
