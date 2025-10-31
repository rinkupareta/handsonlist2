/*
========================================================================================================
Name : 30c.c
Author : Rinku Kumari Pareta
Description : Write a program to create a shared memory.
		c. Detach the shared memory.
Date: 1 Oct, 2025.
========================================================================================================
*/
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    key_t k = ftok(".", 'a');         
    int shmid = shmget(k, 1024, IPC_CREAT | 0666); 

    if (shmid == -1) {
        perror("shmget failed");
        exit(1);
    }
    char *data = shmat(shmid, NULL, 0);  
    if (data == (char *)-1) {
        perror("shmat failed");
        exit(1);
    }
    printf("Attached shared memory.\n");
    shmdt(data);                        
    printf("Detached shared memory.\n");

    return 0;
}
/*Output:
 base  diksha  gcc 30c.c -o 30c
               
 [~/Desktop/SSII/30]
 base  diksha  ./30c
Attached shared memory.
Detached shared memory.
               
 [~/Desktop/SSII/30]
 base  diksha  

*/
