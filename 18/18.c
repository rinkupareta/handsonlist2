/*
========================================================================================================
Name : 18.c
Author : Rinku Kumari Pareta
Description : Write a program to find out total number of directories on the pwd. Execute ls -l | grep ^d | wc. Use only dup2.
Date: 1 Oct, 2025.
========================================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int p1[2], p2[2];
    pid_t pId1, pId2, pId3;
    if (pipe(p1) == -1) { perror("p1"); exit(1); }
    if (pipe(p2) == -1) { perror("p2"); exit(1); }
    pId1 = fork();
    if (pId1 == 0) {
        
        dup2(p1[1], STDOUT_FILENO);
        close(p1[0]); close(p1[1]);
        close(p2[0]); close(p2[1]);
        execlp("ls", "ls", "-l", NULL);
        perror("execlp ls"); exit(1);
    }
    pId2 = fork();
    if (pId2 == 0) {
        
        dup2(p1[0], STDIN_FILENO);
        dup2(p2[1], STDOUT_FILENO);

        close(p1[0]); close(p1[1]);
        close(p2[0]); close(p2[1]);

        execlp("grep", "grep", "^d", NULL);
        perror("execlp grep"); exit(1);
    }

    pId3 = fork();
    if (pId3 == 0) {

        dup2(p2[0], STDIN_FILENO);

        close(p1[0]); close(p1[1]);
        close(p2[0]); close(p2[1]);

        execlp("wc", "wc", NULL);
        perror("execlp wc"); exit(1);
    }

    close(p1[0]); 
    close(p1[1]);
    close(p2[0]); 
    close(p2[1]);
    wait(NULL);
    wait(NULL);
    wait(NULL);

    return 0;
}
/*Output:

 base  diksha  cd ~/Desktop/SSII/18
               
 [~/Desktop/SSII/18]
 base  diksha  gcc 18.c -o 18      
               
 [~/Desktop/SSII/18]
 base  diksha  ./18 
      0       0       0
               
 [~/Desktop/SSII/18]
 base  diksha  ls -l | grep ^d |wc 
      0       0       0
               
 [~/Desktop/SSII/18]
 base  diksha  


*/
