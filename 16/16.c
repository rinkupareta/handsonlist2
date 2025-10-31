/*
========================================================================================================
Name : 16.c
Author : Rinku Kumari Pareta
Description : Write a program to send and receive data from parent to child vice versa. Use two way communication.
Date: 1 Oct, 2025.
========================================================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    int p1[2], p2[2];
    char parent_msg[] = "Hello Child";
    char child_msg[]  = "Hello Parent";
    char buf[100];

    pipe(p1);
    pipe(p2);

    if (fork() == 0) {
        close(p1[1]); 
        close(p2[0]); 

        read(p1[0], buf, sizeof(buf));
        printf("Child got: %s\n", buf);

        write(p2[1], child_msg, strlen(child_msg)+1);

        close(p1[0]); close(p2[1]);
    } else {
        close(p1[0]); 
        close(p2[1]); 

        write(p1[1], parent_msg, strlen(parent_msg)+1);

        read(p2[0], buf, sizeof(buf));
        printf("Parent got: %s\n", buf);

        close(p1[1]); close(p2[0]);
    }
    return 0;
}
/*
Output:
 base  diksha  cd ~/Desktop/SSII/16
               
 [~/Desktop/SSII/16]
 base  diksha  gcc 16.c -o 16      
               
 [~/Desktop/SSII/16]
 base  diksha  ./16
Child got: Hello Child
Parent got: Hello Parent
               
 [~/Desktop/SSII/16]
 base  diksha  
 */
