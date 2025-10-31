/*
========================================================================================================
Name : 13b.c
Author : Rinku Kumari Pareta
Description : Write two programs: first program is waiting to catch SIGSTOP signal, the second program will send the signal (using kill system call). Find out whether the first program is able to catch
the signal or not.
Date: 1 Oct, 2025.
========================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <pid>\n", argv[0]);
        return 1;
    }
    pid_t pid = atoi(argv[1]);
    if (kill(pid, SIGSTOP) == -1) {
        perror("kill");
        return 1;
    }
    printf("Sent SIGSTOP to process %d\n", pid);
    return 0;
}
/*
Output:

Terminal:

base  diksha  cd ~/Desktop/SSII/13
               
 [~/Desktop/SSII/13]
 base  diksha  gcc 13a.c -o 13     
               
 [~/Desktop/SSII/13]
 base  diksha  ./13 
Waiting for SIGSTOP... (try: kill -STOP 85637)
[1]  + 85637 suspended (signal)  ./13
               
 [~/Desktop/SSII/13]
 ✘ base  diksha  

Terminal 2:

base  diksha  cd ~/Desktop/SSII/13
               
 [~/Desktop/SSII/13]
 base  diksha  gcc 13b.c -o 13b    
               
 [~/Desktop/SSII/13]
 base  diksha  ./13b 85637
Sent SIGSTOP to process 85637
               
 [~/Desktop/SSII/13]
 base  diksha  
 */
