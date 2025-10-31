/* 
========================================================================================================
Name : 27a.c
Author : Rinku Kumari Pareta
Description : Write a program to receive messages from the message queue.
                a. with 0 as a flag
Date: 1 Oct, 2025.
========================================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct msgbuf {
    long mtype;
    char mtext[100];
};

int main() {
    key_t k = 1234;  
    int mid = msgget(k, 0666 | IPC_CREAT);
    if (mid == -1) {
        perror("msgget");
        exit(1);
    }
    struct msgbuf msg;
    if (msgrcv(mid, &msg, sizeof(msg.mtext), 1, 0) == -1) {
        perror("msgrcv");
        exit(1);
    }

    printf("Received (blocking): %s\n", msg.mtext);
    return 0;
}
/*
Output:
base  diksha  cd ~/Desktop/SSII/26
               
 [~/Desktop/SSII/26]
 base  diksha  gcc 26.c -o 26      
               
 [~/Desktop/SSII/26]
 base  diksha  ./26
Enter your message: rinku
Message sent to queue (key=1234, id=1)
               

base  diksha  cd ~/Desktop/SSII/27
               
 [~/Desktop/SSII/27]
 base  diksha  gcc 27a.c -o 27a    
               
 [~/Desktop/SSII/27]
 base  diksha  ./27a
Received (blocking): rinku

*/
