/*
========================================================================================================
Name : 9.c
Author : Rinku Kumari Pareta
Description : Write a program to ignore a SIGINT signal then reset the default action of the SIGINT signal - Use signal system call.
Date: 1 Oct, 2025.
========================================================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main() {
    printf("Ignoring SIGINT for 5 seconds. Try pressing Ctrl+C now.\n");
    if (signal(SIGINT, SIG_IGN) == SIG_ERR) {
        perror("signal");
        return 1;
    }
    sleep(5);
    printf("Now resetting SIGINT to default. Ctrl+C will terminate the program.\n");
    if (signal(SIGINT, SIG_DFL) == SIG_ERR) {
        perror("signal");
        return 1;
    }
    for (int i = 0; i < 10; i++) {
        printf("Running... (%d)\n", i+1);
        sleep(1);
    }
    return 0;
}
/*
Output:
base  diksha  cd ~/Desktop/SSII/9
               
 [~/Desktop/SSII/9]
 base  diksha  gcc 9.c -o 9       
               
 [~/Desktop/SSII/9]
 base  diksha  ./9          
Ignoring SIGINT for 5 seconds. Try pressing Ctrl+C now.
^CNow resetting SIGINT to default. Ctrl+C will terminate the program.
Running... (1)
Running... (2)
Running... (3)
Running... (4)
Running... (5)
Running... (6)
Running... (7)
Running... (8)
Running... (9)
^C
               
*/
