/*
========================================================================================================
Name : 32.c
Author : Rinku Kumari Pareta
Description : Write a program to implement semaphore to protect any critical section.
Date: 1 Oct, 2025.
========================================================================================================
*/
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <fcntl.h> 
#include <unistd.h>

sem_t *semaphore;

void* critical_section(void* arg) {
    long threadId = (long)arg;

    printf("To enter critical section thread %ld is waiting .\n", threadId);

    sem_wait(semaphore);
    printf("Thread %ld has entered in critical section.\n", threadId);
    sleep(2); 
    printf("Thread %ld is leaving critical section.\n", threadId);

    sem_post(semaphore); 

    return NULL;
}

int main() {
    // create a named semaphore with initial value = 1 (binary semaphore)
    semaphore = sem_open("/mysem", O_CREAT, 0666, 1);
    if (semaphore == SEM_FAILED) {
        perror("sem_open");
        return 1;
    }

    pthread_t threads[3];

    for (long i = 0; i < 3; i++) {
        pthread_create(&threads[i], NULL, critical_section, (void*)i);
    }

    for (int i = 0; i < 3; i++) {
        pthread_join(threads[i], NULL);
    }

    sem_close(semaphore);
    sem_unlink("/mysem");  // remove semaphore from system

    return 0;
}

/*Output:

base  diksha  cd ~/Desktop/SSII/32
               
 [~/Desktop/SSII/32]
 base  diksha  gcc 32.c -o 32      
               
 [~/Desktop/SSII/32]
 base  diksha  ./32
To enter critical section thread 0 is waiting .
Thread 0 has entered in critical section.
To enter critical section thread 1 is waiting .
To enter critical section thread 2 is waiting .
Thread 0 is leaving critical section.
Thread 1 has entered in critical section.
Thread 1 is leaving critical section.
Thread 2 has entered in critical section.
Thread 2 is leaving critical section.
               
 [~/Desktop/SSII/32]
 base  diksha  


*/
