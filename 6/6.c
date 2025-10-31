/*
========================================================================================================
Name : 6.c
Author : Rinku Kumari Pareta
Description : 6. Write a simple program to create three threads.
Date: 1 Oct, 2025.
========================================================================================================
*/


#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void* thread_func(void* arg) {
    printf("Thread %ld is running\n", (long)arg);
    return NULL;
}
int main() {
    pthread_t t1, t2, t3;

    pthread_create(&t1, NULL, thread_func, (void*)1);
    pthread_create(&t2, NULL, thread_func, (void*)2);
    pthread_create(&t3, NULL, thread_func, (void*)3);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);

    return 0;
}
/*
Output:
 base  diksha  cd ~/Desktop/SSII/6
               
 [~/Desktop/SSII/6]
 base  diksha  gcc 6.c -o 6       
               
 [~/Desktop/SSII/6]
 base  diksha  ./6
Thread 1 is running
Thread 2 is running
Thread 3 is running
               
 [~/Desktop/SSII/6]
 base  diksha 
 */
