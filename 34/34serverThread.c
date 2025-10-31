/*
========================================================================================================
Name : 34serverThread.c
Author : Rinku Kumari Pareta
Description :Write a program to create a concurrent server using pthreads.
Date: 1 Oct, 2025.
========================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void* handle_client(void* arg) {
    int clientSocket = *(int*)arg;
    char buff[BUFFER_SIZE];
    int bytesRead;

    bytesRead = read(clientSocket, buff, sizeof(buff));
    if (bytesRead > 0) {
        printf("Received from client: %s\n", buff);
        write(clientSocket, buff, bytesRead); 
    }

    close(clientSocket);
    return NULL;
}

int main() {
    int serverfd, clientSocket;
    struct sockaddr_in add;
    int addrlen = sizeof(add);
    pthread_t tid;

    serverfd = socket(AF_INET, SOCK_STREAM, 0);
    if (serverfd < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    add.sin_family = AF_INET;
    add.sin_addr.s_addr = INADDR_ANY;
    add.sin_port = htons(PORT);

    if (bind(serverfd, (struct sockaddr*)&add, sizeof(add)) < 0) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    if (listen(serverfd, 5) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d\n", PORT);

    while (1) {
        clientSocket = accept(serverfd, (struct sockaddr*)&add, (socklen_t*)&addrlen);
        if (clientSocket < 0) {
            perror("accept");
            continue;
        }

        pthread_create(&tid, NULL, handle_client, (void*)&clientSocket);
        pthread_detach(tid);  
    }

    close(serverfd);
    return 0;
}
/*
Output:
Terminal 1:
base  diksha  cd ~/Desktop/SSII/34              
 [~/Desktop/SSII/34]
 ✘ base  diksha  gcc 34serverThread.c -o 34serverThread
               
 [~/Desktop/SSII/34]
 base  diksha  ./34serverThread
Server listening on port 8080
Received from client: hii i am rinku              
 [~/Desktop/SSII/34]
 base  diksha  gcc 34serverThread.c -o 34serverThread -pthread
               
 [~/Desktop/SSII/34]
 base  diksha  ./34serverThread                               
Server listening on port 8080
Received from client: hii , i am rinku

Terminal2:
base  diksha  cd ~/Desktop/SSII/34                  
               
 [~/Desktop/SSII/34]
 base  diksha  gcc 34client.c -o 34client
               
 [~/Desktop/SSII/34]
 base  diksha  ./client        
Type message: hii i am rinku
Received from server: hii i am rinku

*/
