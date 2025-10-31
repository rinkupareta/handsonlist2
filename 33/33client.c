/*
========================================================================================================
Name : 33client.c
Author : Rinku Kumari Pareta
Description : Write a program to communicate between two machines using socket.
Date: 1 Oct, 2025.
========================================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define PORT 8080

int main() {
    int sock = 0;
    struct sockaddr_in serv_addr;
    char buff[1024] = {0};
    const char *message = "Hii from client";
    if ((sock= socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation error");
        exit(EXIT_FAILURE);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Server IP: use 127.0.0.1 if same machine
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        perror("Invalid address");
        exit(EXIT_FAILURE);
    }
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Connection Failed");
        exit(EXIT_FAILURE);
    }
    send(sock, message, strlen(message), 0);
    printf("Message sent to server\n");
    read(sock, buff, sizeof(buff));
    printf("Received from server: %s\n", buff);

    close(sock);
    return 0;
}
/*Output:
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
