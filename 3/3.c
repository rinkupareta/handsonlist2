/*
========================================================================================================
Name : 3.c
Author : Rinku Kumari Pareta
Description : Write a program to set (any one) system resource limit. Use setrlimit system call.
Date: 1 Oct, 2025.
========================================================================================================
*/

#include <stdio.h>
#include <sys/resource.h>

int main() {
    struct rlimit limit;

    limit.rlim_cur = 50;
    limit.rlim_max = 50;
    if (setrlimit(RLIMIT_NOFILE, &limit) == 0)
        printf("Open files limit set to 50\n");
    else
        perror("setrlimit");

    return 0;
}
/*
Otput:
 base  diksha  cd ~/Desktop/SSII/3
               
 [~/Desktop/SSII/3]
 base  diksha  gcc 3.c -o 3       
               
 [~/Desktop/SSII/3]
 base  diksha  ./3
Open files limit set to 50
               
 [~/Desktop/SSII/3]
 base  diksha  
*/
