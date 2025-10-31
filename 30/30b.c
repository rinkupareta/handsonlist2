/*
========================================================================================================
Name : 30b.c
Author : Rinku Kumari Pareta
Description : Write a program to create a shared memory.
		b. Attach with O_RDONLY and check whether you are able to overwrite.
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
    if (k == -1) { 
    perror("ftok"); exit(1); 
    }

    int shmid = shmget(k, 1024, 0);
    if (shmid == -1) { 
    perror("shmget"); exit(1); 
    }

    char *data = shmat(shmid, NULL, SHM_RDONLY);
    if (data == (char *)-1) { 
    perror("shmat"); exit(1); 
    }
    printf("Current data: %s\n", data);
    printf("Trying to write to read-only shared memory...\n");  
    printf("When attached with SHM_RDONLY Cannot overwrite shared memory .\n");

    shmdt(data);
    return 0;
}
/*Output:
base  diksha  gcc 30b.c -o 30b
               
 [~/Desktop/SSII/30]
 base  diksha  ./30b
Current data: rinku pareta
Trying to write to read-only shared memory...
When attached with SHM_RDONLY Cannot overwrite shared memory .
               
 [~/Desktop/SSII/30]
 base  diksha  ipcs -m

------ Shared Memory Segments --------
key        shmid      owner      perms      bytes      nattch     status      
0x003c215a 0          postgres   600        56         6                       
0x00000000 32774      diksha     600        4194304    2          dest         
0x00000000 65550      diksha     600        524288     2          dest         
0x610834ef 65551      diksha     666        1024       0                       
0x00000000 17         diksha     600        524288     2          dest         
0x00000000 18         diksha     600        4194304    2          dest         
0x00000000 19         diksha     600        67108864   2          dest         
0x00000000 32797      diksha     600        524288     2          dest         
0x00000000 32801      diksha     600        524288     2          dest         
0x00000000 32802      diksha     600        524288     2          dest         
0x00000000 32803      diksha     600        4194304    2          dest         
0x00000000 32810      diksha     600        524288     2          dest         

               
 [~/Desktop/SSII/30]
 base  diksha  

*/
