/*
========================================================================================================
Name : 1c.c
Author : Rinku Kumari Pareta
Description : Write a separate program (for each time domain) to set a interval timer in 10sec and 10micro second
 		c. ITIMER_PROF
Date: 1 Oct, 2025.
========================================================================================================
*/

#include<stdio.h>
#include <sys/time.h>
#include<signal.h>
#include <unistd.h>

void prof_alarm_handler(int sig) {
    printf("ITIMER_PROF alarm\n");
}
int main(){
    struct itimerval timer;
    
    signal(SIGPROF, prof_alarm_handler);
    
    timer.it_value.tv_sec = 10;
    timer.it_value.tv_usec = 10;
    
    timer.it_interval.tv_sec = 10;
    timer.it_interval.tv_usec = 10;
    
    setitimer(ITIMER_PROF, &timer, NULL);
    while(1){
           for(int i = 0;i<1000;i++);
    }
    return 0;
}

/*
Output:
base  diksha  gcc 1c.c -o 1
               
 [~/Desktop/SSII/1]
 base  diksha  ./1
ITIMER_PROF alarm
ITIMER_PROF alarm

*/
