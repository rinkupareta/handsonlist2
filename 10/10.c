/*
========================================================================================================
Name : 10.c
Author : Rinku Kumari Pareta
Description : Write a separate program using sigaction system call to catch the following signals.
		a. SIGSEGV
		b. SIGINT
		c. SIGFPE
Date: 1 Oct, 2025.
========================================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void signal_handler(int sign) {
    switch (sign) {
        case SIGSEGV:
            printf("Signal SIGSEGV (Segmentation Fault) caught\n");
            exit(1);
        case SIGINT:
            printf("\nSignal SIGINT (Ctrl+C) caught. \nExiting gracefully...\n");
            exit(0);
        case SIGFPE:
            printf("Signal SIGFPE (Floating-point exception) caught\n");
            exit(1);
        default:
            printf("Unexpected signal caught: %d\n", sign);
            exit(1);
    }
}
int main() {
    struct sigaction sa;
    sa.sa_handler = signal_handler;
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGSEGV, &sa, NULL);
    sigaction(SIGINT, &sa, NULL);
    sigaction(SIGFPE, &sa, NULL);

    int choice;
    printf("Choose an option:\n");
    printf("1. Trigger SIGSEGV (Segmentation Fault)\n");
    printf("2. Trigger SIGFPE (Floating Point Exception)\n");
    printf("3. Wait for SIGINT (Press Ctrl+C)\n=> ");
    scanf("%d", &choice);

    if (choice == 1) {
        int *ptr = NULL;
        printf("Triggering SIGSEGV...\n");
        *ptr = 10;
    } 
    else if (choice == 2) {
        int a = 10, b = 0;
        printf("Triggering SIGFPE...\n");
        printf("%d", a / b); 
    } 
    else if (choice == 3) {
        printf("Press Ctrl+C to trigger SIGINT...\n");
        while (1) {
            sleep(1);
        }
    } 
    else {
        printf("Wrong choice.\n");
    }

    return 0;
}
/*
Output:

base  diksha  cd ~/Desktop/SSII/10
               
 [~/Desktop/SSII/10]
 base  diksha  gcc 10.c -o 10      
               
 [~/Desktop/SSII/10]
 base  diksha  ./10 
Choose an option:
1. Trigger SIGSEGV (Segmentation Fault)
2. Trigger SIGFPE (Floating Point Exception)
3. Wait for SIGINT (Press Ctrl+C)
=> 1
Triggering SIGSEGV...
Signal SIGSEGV (Segmentation Fault) caught
               
 [~/Desktop/SSII/10]
 ✘ base  diksha  ./10
Choose an option:
1. Trigger SIGSEGV (Segmentation Fault)
2. Trigger SIGFPE (Floating Point Exception)
3. Wait for SIGINT (Press Ctrl+C)
=> 2
Triggering SIGFPE...
Signal SIGFPE (Floating-point exception) caught
               
 [~/Desktop/SSII/10]
 base  diksha  ./10
Choose an option:
1. Trigger SIGSEGV (Segmentation Fault)
2. Trigger SIGFPE (Floating Point Exception)
3. Wait for SIGINT (Press Ctrl+C)
=> 3
Press Ctrl+C to trigger SIGINT...
^C
Signal SIGINT (Ctrl+C) caught. 
Exiting gracefully...
               
 [~/Desktop/SSII/10]
 base  diksha  

*/
