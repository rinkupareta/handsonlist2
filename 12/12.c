/*
========================================================================================================
Name : 12.c
Author : Rinku Kumari Pareta
Description : Write a program to create an orphan process. Use kill system call to send SIGKILL signal to the parent process from the child process.
Date: 1 Oct, 2025.
========================================================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

int main() {
    pid_t pId = fork();

    if (pId < 0) {
        perror("fork");
        return 1;
    }

    if (pId == 0) {
        sleep(1); 
        pid_t ppid = getppid();
        printf("Child: sending SIGKILL to parent (pid=%d)\n", ppid);
        if (kill(ppid, SIGKILL) == -1) {
            perror("kill");
        }
        sleep(2);
        printf("Child: my new parent pid = %d\n", getppid());
        sleep(2);
        return 0;
    } else {
        printf("Parent: running. PID=%d, child PID=%d\n", getpid(), pId);
        while (1) {
            printf("Parent: still alive...\n");
            sleep(1);
        }
    }
    return 0;
}
/*
Output:
base  diksha  cd ~/Desktop/SSII/12
               
 [~/Desktop/SSII/12]
 base  diksha  gcc 12.c -o 12      
               
 [~/Desktop/SSII/12]
 base  diksha  ./12
Parent: running. PID=84724, child PID=84725
Parent: still alive...
Parent: still alive...
Child: sending SIGKILL to parent (pid=84724)
[2]    84724 killed     ./12
               
 [~/Desktop/SSII/12]
 ✘ base  diksha  Child: my new parent pid = 4865

               
 [~/Desktop/SSII/12]
 ✘ base  diksha  
*/
