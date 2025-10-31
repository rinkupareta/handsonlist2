/*
========================================================================================================
Name : 1a.c
Author : Rinku Kumari Pareta
Description : Write a separate program (for each time domain) to set a interval timer in 10sec and 10micro second
 		a. ITIMER_REAL
Date: 1 Oct, 2025.
========================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>

void handler(int snum) {
    printf("Timer expired! Signal = %d\n", snum);
}

int main() {
    struct itimerval timer;
    signal(SIGALRM, handler);
    timer.it_value.tv_sec = 10;
    timer.it_value.tv_usec = 10;
    timer.it_interval.tv_sec = 10;   
    timer.it_interval.tv_usec = 10;

    setitimer(ITIMER_REAL, &timer, NULL);

    while (1) {
        pause(); 
    }
    return 0;
}

/*
output:
 base  diksha  cd ~/Desktop/SSII/1
                           
 [~/Desktop/SSII/1]
 base  diksha  gcc 1a.c -o 1
               
 [~/Desktop/SSII/1]
 base  diksha  ./1          
Timer expired! Signal = 14
Timer expired! Signal = 14

*/
