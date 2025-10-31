/*
========================================================================================================
Name : 34client.c
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

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in serv_addr;
    char buff[BUFFER_SIZE];

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr); 

    connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

    printf("Type message: ");
    fgets(buff, sizeof(buff), stdin);

    send(sock, buff, strlen(buff), 0); 
    read(sock, buff, sizeof(buff));   

    printf("Received from server: %s\n", buff);

    close(sock);
    return 0;
}

/*Output:
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
