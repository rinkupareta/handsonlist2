/*
========================================================================================================
Name : 32.c
Author : Rinku Kumari Pareta
Description :  Write a program to implement semaphore to protect any critical section. 
c. protect multiple pseudo resources ( may be two) using counting semaphore 
Date: 1 Oct, 2025.
========================================================================================================
*/

#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <fcntl.h>
#include <unistd.h>

#define NUM_THREADS 5

sem_t *semaphore;

void* criticalSection(void* arg) {
    long threadId = (long)arg;

    printf(" In the critical section thread %ld is waiting to enter.\n", threadId);

    sem_wait(semaphore); 
    printf("Thread %ld has entered the critical section.\n", threadId);

    sleep(2); 

    printf("Thread %ld is leaving the critical section.\n", threadId);
    sem_post(semaphore); 

    return NULL;
}

int main() {
    semaphore = sem_open("/countsem", O_CREAT, 0666, 2);
    if (semaphore == SEM_FAILED) {
        perror("sem_open");
        return 1;
    }

    pthread_t threads[NUM_THREADS];

    for (long i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, criticalSection, (void*)i);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    sem_close(semaphore);
    sem_unlink("/countsem");  

    return 0;
}


/*
Output:
base  diksha  cd ~/Desktop/SSII/32
                      
 [~/Desktop/SSII/32]
 ✘ base  diksha  gcc 32c.c -o 32c
       
 [~/Desktop/SSII/32]
 base  diksha  ./32c     
 In the critical section thread 0 is waiting to enter.
Thread 0 has entered the critical section.
 In the critical section thread 1 is waiting to enter.
Thread 1 has entered the critical section.
 In the critical section thread 3 is waiting to enter.
 In the critical section thread 2 is waiting to enter.
 In the critical section thread 4 is waiting to enter.
Thread 0 is leaving the critical section.
Thread 1 is leaving the critical section.
Thread 3 has entered the critical section.
Thread 2 has entered the critical section.
Thread 3 is leaving the critical section.
Thread 2 is leaving the critical section.
Thread 4 has entered the critical section.
Thread 4 is leaving the critical section.
               
 [~/Desktop/SSII/32]
 base  diksha  


*/







