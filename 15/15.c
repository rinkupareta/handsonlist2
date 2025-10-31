/*
========================================================================================================
Name : 15.c
Author : Rinku Kumari Pareta
Description : Write a simple program to send some data from parent to the child process.
Date: 1 Oct, 2025.
========================================================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd[2];
    char msg[] = "Message from parent to child";
    char buf[100];

    pipe(fd);
    if (fork() == 0) {
        close(fd[1]);
        read(fd[0], buf, sizeof(buf));
        printf("Child got: %s\n", buf);
        close(fd[0]);
    } else {
        close(fd[0]);
        write(fd[1], msg, strlen(msg)+1);
        close(fd[1]);
    }
    return 0;
}
/*
Output:
 base  diksha  cd ~/Desktop/SSII/15
               
 [~/Desktop/SSII/15]
 base  diksha  gcc 15.c -o 15      
               
 [~/Desktop/SSII/15]
 base  diksha  ./15
Child got: Message from parent to child
               
 [~/Desktop/SSII/15]
 base  diksha  
*/
