/*
========================================================================================================
Name : 4.c
Author : Rinku Kumari Pareta
Description : Write a program to measure how much time is taken to execute 100 getppid ( ) system call. Use time stamp counter.
Date: 1 Oct, 2025.
========================================================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <x86intrin.h>  

int main() {
    unsigned long long start, end;
    int i;

    start = __rdtsc(); 
    for (i = 0; i < 100; i++) {
        getppid();
    }
    end = __rdtsc();
    printf("CPU cycles taken for 100 getppid() calls: %llu\n", end - start);
    return 0;
}
/*
Output:
 base  diksha  cd ~/Desktop/SSII/4
               
 [~/Desktop/SSII/4]
 base  diksha  gcc 4.c -o 4       
               
 [~/Desktop/SSII/4]
 base  diksha  ./4
CPU cycles taken for 100 getppid() calls: 71098
               
 [~/Desktop/SSII/4]
 base  diksha  

*/
