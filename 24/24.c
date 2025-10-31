/*
========================================================================================================
Name : 24.c
Author : Rinku Kumari Pareta
Description : Write a program to create a message queue and print the key and message queue id.
Date: 1 Oct, 2025.
========================================================================================================
*/
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    key_t k = ftok(".", 'a');
    if (k == -1) {
        perror("ftok");
        exit(1);
    }
    int mid = msgget(k, IPC_CREAT | 0666);
    if (mid == -1) {
        perror("msgget");
        exit(1);
    }
    printf("Key is : %d, ID is: %d\n", k, mid);

    return 0;
}
/*Output:
base  diksha  cd ~/Desktop/SSII/24
               
 [~/Desktop/SSII/24]
 base  diksha  gcc 24.c -o 24      
               
 [~/Desktop/SSII/24]
 base  diksha  ./24
Key is : 1627926144, ID is: 1
               
 [~/Desktop/SSII/24]
 base  diksha  


*/
