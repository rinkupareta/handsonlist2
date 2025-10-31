/*
========================================================================================================
Name : 17a.c
Author : Rinku Kumari Pareta
Description : Write a program to execute ls -l | wc.
              a. use dup
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
        close(1);                   
        dup(fd[1]);              
        execlp("ls", "ls", "-l", NULL);
        perror("execlp ls");
        exit(1);
    } else {
        close(fd[1]);              
        close(0);                   
        dup(fd[0]);                
        execlp("wc", "wc", NULL);
        perror("execlp wc");
        exit(1);
    }
    return 0;
}
/*
Output:
base  diksha  cd ~/Desktop/SSII/17
               
 [~/Desktop/SSII/17]
 base  diksha  gcc 17a.c -o 17a   
               
 [~/Desktop/SSII/17]
 base  diksha  ./17a
      5      38     215
               
 [~/Desktop/SSII/17]
 base  diksha  

*/
