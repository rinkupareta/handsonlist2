/*
========================================================================================================
Name : 2.c
Author : Rinku Kumari Pareta
Description : Write a program to print the system resource limits. Use getrlimit system call.
Date: 1 Oct, 2025.
========================================================================================================
*/

#include <stdio.h>
#include <sys/resource.h>

int main() {
    struct rlimit limit;

    getrlimit(RLIMIT_CPU, &limit);
    printf("CPU time limit: %ld\n", limit.rlim_cur);

    getrlimit(RLIMIT_FSIZE, &limit);
    printf("File size limit: %ld\n", limit.rlim_cur);

    getrlimit(RLIMIT_NOFILE, &limit);
    printf("Open files limit: %ld\n", limit.rlim_cur);

    return 0;
}
/*
Output:
base  diksha  cd ~/Desktop/SSII/2 
               
 [~/Desktop/SSII/2]
 base  diksha  gcc 2.c -o 2       
               
 [~/Desktop/SSII/2]
 base  diksha  ./2 
CPU time limit: -1
File size limit: -1
Open files limit: 1024
               
 [~/Desktop/SSII/2]
 base  diksha  

*/
