/* 
========================================================================================================
Name : 27b.c
Author : Rinku Kumari Pareta
Description : Write a program to receive messages from the message queue.
                 b. with IPC_NOWAIT as a flag
Date: 1 Oct, 2025.
========================================================================================================
*/
/* 27b.c - Message Queue Receiver (non-blocking) */
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <errno.h>
#include <string.h>

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
    int ret = msgrcv(mid, &msg, sizeof(msg.mtext), 1, IPC_NOWAIT);

    if (ret == -1) {
        if (errno == ENOMSG) {
            printf("No message available in queue (non-blocking).\n");
        } else {
            perror("msgrcv");
        }
    } else {
        msg.mtext[ret] = '\0';  
        printf("Received (non-blocking): %s\n", msg.mtext);
    }
    return 0;
}
/*
Output:
 base  diksha  cd ~/Desktop/SSII/26
               
 [~/Desktop/SSII/26]
 base  diksha  gcc 26.c -o 26      
               
 [~/Desktop/SSII/26]
 base  diksha  ./26                
Enter your message: pareta
Message sent to queue (key=1234, id=1)
               
 [~/Desktop/SSII/26]
 base  diksha  cd ~/Desktop/SSII/27
               
 [~/Desktop/SSII/27]
 base  diksha  gcc 27b.c -o 27b  
               
 [~/Desktop/SSII/27]
 base  diksha  ./27b
Received (non-blocking): pareta

               
 [~/Desktop/SSII/27]
 base  diksha  
*/
