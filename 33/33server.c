/*
========================================================================================================
Name : 34server.c
Author : Rinku Kumari Pareta
Description : Write a program to create a concurrent server using fork.
Date: 1 Oct, 2025.
========================================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/wait.h>

#define PORT 8081
#define BUFFER_SIZE 1024

int main() {
    int serverfd, clientSocket;
    struct sockaddr_in add;
    int addrlen = sizeof(add);
    char buff[BUFFER_SIZE];
    pid_t pId;
    serverfd = socket(AF_INET, SOCK_STREAM, 0);
    if (serverfd == -1) {
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
        pId = fork();
        if (pId == 0) {
            close(serverfd);
            memset(buff, 0, BUFFER_SIZE);

            int bytesRead = read(clientSocket, buff, BUFFER_SIZE);
            if (bytesRead > 0) {
                printf("Received from client: %s\n", buff);
                write(clientSocket, buff, bytesRead); 
            }
            close(clientSocket);
            exit(0); 
        } else if (pId > 0) {
            close(clientSocket); 
            waitpId(-1, NULL, WNOHANG); 
        } else {
            perror("fork");
            close(clientSocket);
        }
    }

    close(serverfd);
    return 0;
}

/*
Output:
Terminal 1:
base  diksha  cd ~/Desktop/SSII/33    
               
 [~/Desktop/SSII/33]
 base  diksha  gcc 33server.c -o server
               
 [~/Desktop/SSII/33]
 base  diksha  gcc 33client.c -o client
               
 [~/Desktop/SSII/33]
 base  diksha  ./server
Server is listening on port 8080
Received from client: Hii from client
Response is sent to client
               
 [~/Desktop/SSII/33]
 base  diksha  

Terminal 2:

base  diksha  cd ~/Desktop/SSII/33    
               
 [~/Desktop/SSII/33]
 base  diksha  gcc 33server.c -o server
               
 [~/Desktop/SSII/33]
 base  diksha  gcc 33client.c -o client
               
 [~/Desktop/SSII/33]
 base  diksha  ./client
Message sent to server
Received from server: Hii from server
               
 [~/Desktop/SSII/33]
 base  diksha  

*/
