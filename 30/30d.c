/*
========================================================================================================
Name : 30d.c
Author : Rinku Kumari Pareta
Description : Write a program to create a shared memory.
		d. remove the shared memory
Date: 1 Oct, 2025.
========================================================================================================
*/
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>

int main() {
    key_t k = ftok(".", 'a');           
    int shmid = shmget(k, 1024, 0);    
    if (shmid == -1) {
      printf(" there is no shared memory exists with this key.\n");
        return 1;
    }
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {  
        printf("Failed to remove shared memory.\n");
        return 1;
    }
    printf("Shared memory successfully removed.\n");
    return 0;
}
/*Output:
[~/Desktop/SSII/30]
 base  diksha  gcc 30d.c -o 30d
               
 [~/Desktop/SSII/30]
 base  diksha  ./30d
Shared memory successfully removed.
               
 [~/Desktop/SSII/30]
 base  diksha  
 */
