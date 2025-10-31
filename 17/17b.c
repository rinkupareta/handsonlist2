/*
========================================================================================================
Name : 17b.c
Author : Rinku Kumari Pareta
Description : Write a program to execute ls -l | wc.
              b. use dup2
Date: 1 Oct, 2025.
========================================================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    int fd[2];
    pipe(fd);

    if (fork() == 0) {
        close(fd[0]);                       
        dup2(fd[1], STDOUT_FILENO);          
        close(fd[1]);
        execlp("ls", "ls", "-l", NULL);
        perror("execlp ls");
        exit(1);
    } else {
        
        close(fd[1]);                        
        dup2(fd[0], STDIN_FILENO);          
        close(fd[0]);
        execlp("wc", "wc", NULL);
        perror("execlp wc");
        exit(1);
    }
    return 0;
}
/*
Output:

base  diksha  gcc 17b.c -o 17b
               
 [~/Desktop/SSII/17]
 base  diksha  ./17b
      6      47     265
               
 [~/Desktop/SSII/17]
 base  diksha  
 */
