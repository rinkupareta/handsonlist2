/*
========================================================================================================
Name : 32a.c
Author : Rinku Kumari Pareta
Description : Write a program to implement semaphore to protect any critical section.
		a. Rewrite the ticket number creation program using semaphore.
Date: 1 Oct, 2025.
========================================================================================================
*/
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <fcntl.h>  
#include <unistd.h>

#define NUM_THREADS 3

int ticketNum= 0;
sem_t *semaphore;

void* generate_ticket(void* arg) {
    long tId = (long)arg;
    printf("Thread %ld is waiting to generate a ticket.\n", tId);
    sem_wait(semaphore); 
    ticketNum++;
    printf("Thread %ld generated ticket number: %d\n", tId, ticketNum);
    sleep(1); 
    sem_post(semaphore); 

    return NULL;
}
int main() {
   
    semaphore = sem_open("/ticketsem", O_CREAT, 0666, 1);
    if (semaphore == SEM_FAILED) {
        perror("sem_open");
        return 1;
    }
    pthread_t threads[NUM_THREADS];
    for (long i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, generate_ticket, (void*)i);
    }
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    sem_close(semaphore);
    sem_unlink("/ticketsem"); 

    return 0;
}
/*Output:d
base  diksha  gcc 32a.c -o 32a
               
 [~/Desktop/SSII/32]
 base  diksha  ./32a
Thread 0 is waiting to generate a ticket.
Thread 2 is waiting to generate a ticket.
Thread 1 is waiting to generate a ticket.
Thread 0 generated ticket number: 1
Thread 2 generated ticket number: 2
Thread 1 generated ticket number: 3
               
 [~/Desktop/SSII/32]
 base  diksha  


*/
