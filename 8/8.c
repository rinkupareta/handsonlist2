/*
========================================================================================================
Name : 8.c
Author : Rinku Kumari Pareta
Description : Write a separate program using signal system call to catch the following signals.
              a. SIGSEGV
              b. SIGINT
              c. SIGFPE
              d. SIGALRM (use alarm system call)
              e. SIGALRM (use setitimer system call)
              f. SIGVTALRM (use setitimer system call)
              g. SIGPROF (use setitimer system call)
Date: 1 Oct, 2025.
========================================================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

void handler(int sign) {
    switch(sign) {
        case SIGSEGV:   printf("SIGSEGV (Segmentation Fault) caught\n"); break;
        case SIGINT:    printf("SIGINT (Ctrl+C) caught\n"); break;
        case SIGFPE:    printf("SIGFPE (Divide by Zero) caught\n"); break;
        case SIGALRM:   printf("SIGALRM (Timer/Alarm) caught\n"); break;
        case SIGVTALRM: printf("SIGVTALRM (Virtual Timer) caught\n"); break;
        case SIGPROF:   printf("SIGPROF (Profiling Timer) caught\n"); break;
        default:        printf("Signal %d caught\n", sign);
    }
    exit(0);
}

int main() {
    int c;
    struct itimerval timer;
    signal(SIGSEGV, handler);
    signal(SIGINT, handler);
    signal(SIGFPE, handler);
    signal(SIGALRM, handler);
    signal(SIGVTALRM, handler);
    signal(SIGPROF, handler);
    printf("Choose a signal to demonstrate:\n");
    printf("1. SIGSEGV (Segmentation Fault)\n");
    printf("2. SIGINT  (Press Ctrl+C)\n");
    printf("3. SIGFPE  (Divide by Zero)\n");
    printf("4. SIGALRM using alarm()\n");
    printf("5. SIGALRM using setitimer()\n");
    printf("6. SIGVTALRM using setitimer()\n");
    printf("7. SIGPROF using setitimer()\n");
    printf("Enter choice: ");
    scanf("%d", &c);
    switch(c) {
        case 1: {
            int *p = NULL;
            *p = 10;   
            break;
        }
        case 2: {
            printf("To trigger SIGINT press Ctrl+C\n");
            while(1) sleep(1);
            break;
        }
        case 3: {
            int a = 5 / 0;   
            (void)a;
            break;
        }
        case 4: {
            alarm(3);   
            printf("Waiting for SIGALRM (alarm)\n");
            pause();
            break;
        }
        case 5: {
            timer.it_value.tv_sec = 2;
            timer.it_value.tv_usec = 0;
            timer.it_interval.tv_sec = 0;
            timer.it_interval.tv_usec = 0;
            setitimer(ITIMER_REAL, &timer, NULL);
            printf("Waiting for SIGALRM (setitimer)\n");
            pause();
            break;
        }
        case 6: {
            timer.it_value.tv_sec = 1;
            timer.it_value.tv_usec = 0;
            timer.it_interval.tv_sec = 0;
            timer.it_interval.tv_usec = 0;
            setitimer(ITIMER_VIRTUAL, &timer, NULL);
            printf("Busy loop waiting for SIGVTALRM\n");
            while(1);   
            break;
        }
        case 7: {
            timer.it_value.tv_sec = 1;
            timer.it_value.tv_usec = 0;
            timer.it_interval.tv_sec = 0;
            timer.it_interval.tv_usec = 0;
            setitimer(ITIMER_PROF, &timer, NULL);
            printf("Busy loop waiting for SIGPROF\n");
            while(1);   
            break;
        }
        default:
            printf("Wrong choice!\n");
    }

    return 0;
}
/*Output:
base  diksha  cd ~/Desktop/SSII/8                            
[~/Desktop/SSII/8]
base  diksha  gcc 8.c -o 8 
 [~/Desktop/SSII/8]
 base  diksha  ./8       
Choose a signal to demonstrate:
1. SIGSEGV (Segmentation Fault)
2. SIGINT  (Press Ctrl+C)
3. SIGFPE  (Divide by Zero)
4. SIGALRM using alarm()
5. SIGALRM using setitimer()
6. SIGVTALRM using setitimer()
7. SIGPROF using setitimer()
Enter choice: 4
Waiting for SIGALRM (alarm)
SIGALRM (Timer/Alarm) caught
               
 [~/Desktop/SSII/8]
 base  diksha  


*/
