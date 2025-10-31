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

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int serverfd, clientSocket;
    struct sockaddr_in add;
    int addrlen = sizeof(add);
    char buff[BUFFER_SIZE];
    pid_t pid;

    // Create socket
    serverfd = socket(AF_INET, SOCK_STREAM, 0);
    if (serverfd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }
    int opt = 1;
    if (setsockopt(serverfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    // Bind socket
    add.sin_family = AF_INET;
    add.sin_addr.s_addr = INADDR_ANY;
    add.sin_port = htons(PORT);

    if (bind(serverfd, (struct sockaddr*)&add, sizeof(add)) < 0) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    // Listen for connections
    if (listen(serverfd, 5) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d\n", PORT);

    // Accept loop
    while (1) {
        clientSocket = accept(serverfd, (struct sockaddr*)&add, (socklen_t*)&addrlen);
        if (clientSocket < 0) {
            perror("accept");
            continue;
        }

        pid = fork();
        if (pid == 0) {  // Child process
            close(serverfd); 
            memset(buff, 0, BUFFER_SIZE);

            int bytesRead = read(clientSocket, buff, BUFFER_SIZE);
            if (bytesRead > 0) {
                printf("Received from client: %s\n", buff);
                write(clientSocket, buff, bytesRead);  // Echo back
            }

            close(clientSocket);
            exit(0); 
        } else if (pid > 0) {  // Parent process
            close(clientSocket); 
            waitpid(-1, NULL, WNOHANG); 
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
base  diksha  cd ~/Desktop/SSII/34      
               
 [~/Desktop/SSII/34]
 base  diksha  gcc 34server.c -o 34server
               
 [~/Desktop/SSII/34]
 base  diksha  ./34server                
bind: Address already in use
               
 [~/Desktop/SSII/34]
 ✘ base  diksha  sudo lsof -i :8080    
[sudo] password for diksha: 
COMMAND    PID   USER   FD   TYPE DEVICE SIZE/OFF NODE NAME
34serverT 9689 diksha    3u  IPv4  31410      0t0  TCP *:http-alt (LISTEN)
               
 [~/Desktop/SSII/34]
 base  diksha  kill -9 9689    
               
 [~/Desktop/SSII/34]
 base  diksha  sudo lsof -i :8080
               
 [~/Desktop/SSII/34]
 ✘ base  diksha  ./34server      
Server listening on port 8080
Received from client: rinku 

Terminal 2:
base  diksha  gcc 34client.c -o 34client
               
 [~/Desktop/SSII/34]
 base  diksha  ./34client                
Type message: rinku 
Received from server: rinku 
*/
    
