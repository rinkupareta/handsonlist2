/*
========================================================================================================
Name : 14.c
Author : Rinku Kumari Pareta
Description : Write a simple program to create a pipe, write to the pipe, read from pipe and display on the monitor.
Date: 1 Oct, 2025.
========================================================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd[2];
    char write_msg[] = "Hello via pipe!";
    char read_msg[100];

    if (pipe(fd) == -1) {
        perror("pipe");
        return 1;
    }
    if (fork() == 0) {
        close(fd[1]);  
        read(fd[0], read_msg, sizeof(read_msg));
        printf("Child received: %s\n", read_msg);
        close(fd[0]);
    } else {
        close(fd[0]);  
        write(fd[1], write_msg, strlen(write_msg)+1);
        close(fd[1]);
    }
    return 0;
}
/*
Output:
base  diksha  cd ~/Desktop/SSII/14
               
 [~/Desktop/SSII/14]
 base  diksha  gcc 14.c -o 14      
               
 [~/Desktop/SSII/14]
 base  diksha  ./14         
Child received: Hello via pipe!
               
 [~/Desktop/SSII/14]
 base  diksha  
*/
