/*
========================================================================================================
Name : 32d.c
Author : Rinku Kumari Pareta
Description : Write a program to implement semaphore to protect any critical section.
		d. remove the created semaphore
Date: 1 Oct, 2025.
========================================================================================================
*/
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define NUM_THREADS 3
#define NUM_RESOURCES 2

sem_t semaphore;

void* use_resource(void* arg) {
    long tId = (long)arg;

    printf("Thread %ld is waiting for a resource.\n", tId);
    sem_wait(&semaphore); 

    printf("Thread %ld has acquired a resource.\n", tId);
    sleep(2);       

    printf("Thread %ld is releasing the resource.\n", tId);
    sem_post(&semaphore);  
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];

    sem_init(&semaphore, 0, NUM_RESOURCES);  
    for (long i = 0; i < NUM_THREADS; i++)
        pthread_create(&threads[i], NULL, use_resource, (void*)i);

    for (int i = 0; i < NUM_THREADS; i++)
        pthread_join(threads[i], NULL);

    sem_destroy(&semaphore);
    printf("Semaphore successfully destroyed.\n");
    return 0;
}
/*Output:
base  diksha  gcc 32d.c -o 32d
               
 [~/Desktop/SSII/32]
 base  diksha  ./32d
Thread 0 is waiting for a resource.
Thread 0 has acquired a resource.
Thread 2 is waiting for a resource.
Thread 2 has acquired a resource.
Thread 1 is waiting for a resource.
Thread 0 is releasing the resource.
Thread 2 is releasing the resource.
Thread 1 has acquired a resource.
Thread 1 is releasing the resource.
Semaphore successfully destroyed.
               
 [~/Desktop/SSII/32]
 base  diksha  



*/
