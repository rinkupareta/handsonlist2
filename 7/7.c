/*
========================================================================================================
Name : 7.c
Author : Rinku Kumari Pareta
Description : Write a simple program to print the created thread ids.
Date: 1 Oct, 2025.
========================================================================================================
*/


#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void* thread_func(void* arg) {
    printf("Thread ID: %lu\n", pthread_self());
    return NULL;
}

int main() {
    pthread_t t1, t2, t3;

    pthread_create(&t1, NULL, thread_func, NULL);
    pthread_create(&t2, NULL, thread_func, NULL);
    pthread_create(&t3, NULL, thread_func, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);

    return 0;
}
/*
Output:
 base  diksha  cd ~/Desktop/SSII/7
               
 [~/Desktop/SSII/7]
 base  diksha  gcc 7.c -o 7       
               
 [~/Desktop/SSII/7]
 base  diksha  ./7                    
Thread ID: 137270487152320
Thread ID: 137270478759616
Thread ID: 137270470366912
               
 [~/Desktop/SSII/7]
 base  diksha  
 */
