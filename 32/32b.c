/*
========================================================================================================
Name : 32b.c
Author : Rinku Kumari Pareta
Description : Write a program to implement semaphore to protect any critical section.
		b. protect shared memory from concurrent write access
Date: 1 Oct, 2025.
========================================================================================================
*/
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <fcntl.h>   
#include <unistd.h>

#define NUM_THREADS 3

int shared_memory = 0;
sem_t *semaphore;

void* write_to_shared_memory(void* arg) {
    long tId = (long)arg;

    printf("Thread %ld is waiting to write to shared memory.\n", tId);

    sem_wait(semaphore); 
    int te = shared_memory;
    printf("Thread %ld reads shared memory: %d\n", tId, te);

    sleep(1); 
    te += 10;
    shared_memory = te;
    printf("Thread %ld writes shared memory: %d\n", tId, shared_memory);

    sem_post(semaphore); 
    return NULL;
}

int main() {
    semaphore = sem_open("/shmsem", O_CREAT, 0666, 1);
    if (semaphore == SEM_FAILED) {
        perror("sem_open");
        return 1;
    }
   pthread_t threads[NUM_THREADS];

    for (long i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, write_to_shared_memory, (void*)i);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    sem_close(semaphore);
    sem_unlink("/shmsem"); 
    return 0;
}
/*Output:

base  diksha  gcc 32b.c -o 32b
               
 [~/Desktop/SSII/32]
 base  diksha  ./32b
Thread 0 is waiting to write to shared memory.
Thread 0 reads shared memory: 0
Thread 2 is waiting to write to shared memory.
Thread 1 is waiting to write to shared memory.
Thread 0 writes shared memory: 10
Thread 2 reads shared memory: 10
Thread 2 writes shared memory: 20
Thread 1 reads shared memory: 20
Thread 1 writes shared memory: 30
               
 [~/Desktop/SSII/32]
 base  diksha  


*/
