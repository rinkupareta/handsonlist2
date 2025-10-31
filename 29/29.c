/* 
========================================================================================================
Name : 29.c
Author : Rinku Kumari Pareta
Description : Write a program to remove the message queue.
Date: 1 Oct, 2025.
========================================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main() {
    key_t k = 1234;   
    int mid = msgget(k, 0666);
    if (mid == -1) {
        perror("msgget");
        exit(1);
    }
    if (msgctl(mid, IPC_RMID, NULL) == -1) {
        perror("msgctl");
        exit(1);
    }
    printf("Message queue with key : %d removed successfully.\n", k);
    return 0;
}
/*
Output:
base  diksha  cd ~/Desktop/SSII/29
               
 [~/Desktop/SSII/29]
 base  diksha  gcc 29.c -o 29      
               
 [~/Desktop/SSII/29]
 base  diksha  ./29 
Message queue with key : 1234 removed successfully.
               
 [~/Desktop/SSII/29]
 base  diksha  

 base  diksha  ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages    
0x780834eb 0          diksha     666        100          1           

               
 [~/Desktop/SSII/29]
 base  diksha  


*/
