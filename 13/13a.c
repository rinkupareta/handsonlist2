/*
========================================================================================================
Name : 13a.c
Author : Rinku Kumari Pareta
Description : Write two programs: first program is waiting to catch SIGSTOP signal, the second program will send the signal (using kill system call). Find out whether the first program is able to catch
the signal or not.
Date: 1 Oct, 2025.
========================================================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handler(int sign) {
    printf("Caught SIGSTOP (signal %d)\n", sign);
}
int main() {
    signal(SIGSTOP, handler);  
    printf("Waiting for SIGSTOP... (try: kill -STOP %d)\n", getpid());
    while (1) {
        sleep(1);
    }
    return 0;
}
/*
Output:
Terminal 1:

base  diksha  cd ~/Desktop/SSII/13
               
 [~/Desktop/SSII/13]
 base  diksha  gcc 13a.c -o 13     
               
 [~/Desktop/SSII/13]
 base  diksha  ./13         
Waiting for SIGSTOP... (try: kill -STOP 84858)
[2]  + 84858 suspended (signal)  ./13
               
 [~/Desktop/SSII/13]
 ✘ ⚙ base  diksha  

terminal 2:
 base  diksha  cd ~/Desktop/SSII/13
               
 [~/Desktop/SSII/13]
 base  diksha  gcc 13a.c -o 13     
               
 [~/Desktop/SSII/13]
 base  diksha  kill -STOP 84858         
               
 [~/Desktop/SSII/13]
 base  diksha  
*/
