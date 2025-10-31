/*
========================================================================================================
Name : 11.c
Author : Rinku Kumari Pareta
Description : Write a program to ignore a SIGINT signal then reset the default action of the SIGINT signal - use sigaction system call.
Date: 1 Oct, 2025.
========================================================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>

int main() {
    struct sigaction sa_ignore, sa_old;

    memset(&sa_ignore, 0, sizeof(sa_ignore));
    sa_ignore.sa_handler = SIG_IGN;
    
    if (sigaction(SIGINT, &sa_ignore, &sa_old) == -1) {
        perror("sigaction - ignore");
        return 1;
    }
    printf("SIGINT ignored for 5 seconds. Try Ctrl+C now.\n");
    sleep(5);
    if (sigaction(SIGINT, &sa_old, NULL) == -1) {
        perror("sigaction - restore");
        return 1;
    }
    printf("SIGINT restored. Ctrl+C will now use previous action (likely terminate).\n");
    for (int i = 0; i < 10; i++) {
        printf("Loop %d\n", i+1);
        sleep(1);
    }
    return 0;
}
/*
Output:
 ✘ base  diksha  cd ~/Desktop/SSII/11
               
 [~/Desktop/SSII/11]
 base  diksha  gcc 11.c -o 11    
               
 [~/Desktop/SSII/11]
 base  diksha  ./11 
SIGINT ignored for 5 seconds. Try Ctrl+C now.
^CSIGINT restored. Ctrl+C will now use previous action (likely terminate).
Loop 1
Loop 2
Loop 3
Loop 4
Loop 5
Loop 6
^C
               
 [~/Desktop/SSII/11]
 ✘ base  diksha  
*/
