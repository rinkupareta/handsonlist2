/*
========================================================================================================
Name : 31.c
Author : Rinku Kumari Pareta
Description : Write a program to create a semaphore and initialize value to the semaphore.
		a. Create a binary semaphore.
		b. Create a counting semaphore.
Date: 1 Oct, 2025.
========================================================================================================
*/
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/sem.h>

struct semun {
    int v;
};

int main() {
    key_t k = ftok(".", 'a');
    int semid = semget(k, 1, IPC_CREAT | 0666);

    struct semun arg;
    int c;

    printf("1. Binary Semaphore\n 2. Counting Semaphore\n. Enter choice: ");
    scanf("%d", &c);

    arg.v = (c == 1) ? 1 : 5; 
    semctl(semid, 0, SETVAL, arg);
    int cur = semctl(semid, 0, GETVAL);
    if (cur != -1)
        printf(" Semaphore created successfully.\n ID is : %d, Current Value is :  %d\n", semid, cur);
    else
        perror("semctl (GETVAL) failed");

    return 0;
}

/*Output:

base  diksha  cd ~/Desktop/SSII/31

base  diksha  gcc 31.c -o 31
               
 [~/Desktop/SSII/31]
 base  diksha  ./31
1. Binary Semaphore
 2. Counting Semaphore
. Enter choice: 1
 Semaphore created successfully.
 ID is : 0, Current Value is :  1
               
 [~/Desktop/SSII/31]
 base  diksha  ipcs -s

------ Semaphore Arrays --------
key        semid      owner      perms      nsems     
0x610834f0 0          diksha     666        1         

               
 [~/Desktop/SSII/31]
 base  diksha  gcc 31.c -o 31
               
 [~/Desktop/SSII/31]
 base  diksha  ./31
1. Binary Semaphore
 2. Counting Semaphore
. Enter choice: 2
 Semaphore created successfully.
 ID is : 0, Current Value is :  5
               
 [~/Desktop/SSII/31]
 base  diksha  ipcs -s

------ Semaphore Arrays --------
key        semid      owner      perms      nsems     
0x610834f0 0          diksha     666        1         

               
 [~/Desktop/SSII/31]
 base  diksha  

*/
