/*
========================================================================================================
Name : 5.c
Author : Rinku Kumari Pareta
Description : Write a program to print the system limitation of
a. maximum length of the arguments to the exec family of functions.
b. maximum number of simultaneous process per user id.
c. number of clock ticks (jiffy) per second.
d. maximum number of open files
e. size of a page
f. total number of pages in the physical memory
g. number of currently available pages in the physical memory.
Date: 1 Oct, 2025.
========================================================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/sysinfo.h>
#include <limits.h>

int main() {
    long arg_max = sysconf(_SC_ARG_MAX);
    long max_proc = sysconf(_SC_CHILD_MAX);
    long clk_tick = sysconf(_SC_CLK_TCK);
    long open_files = sysconf(_SC_OPEN_MAX);
    long page_size = sysconf(_SC_PAGESIZE);
    long phys_pages = sysconf(_SC_PHYS_PAGES);
    long avail_pages = sysconf(_SC_AVPHYS_PAGES);

    printf("a. Max length of arguments to exec: %ld\n", arg_max);
    printf("b. Max simultaneous processes per user id: %ld\n", max_proc);
    printf("c. Number of clock ticks per second: %ld\n", clk_tick);
    printf("d. Max number of open files: %ld\n", open_files);
    printf("e. Size of a page: %ld bytes\n", page_size);
    printf("f. Total number of pages in physical memory: %ld\n", phys_pages);
    printf("g. Available pages in physical memory: %ld\n", avail_pages);

    return 0;
}
/*
Otput:
 base  diksha  cd ~/Desktop/SSII/5
               
 [~/Desktop/SSII/5]
 base  diksha  gcc 5.c -o 5       
               
 [~/Desktop/SSII/5]
 base  diksha  ./5
a. Max length of arguments to exec: 2097152
b. Max simultaneous processes per user id: 60382
c. Number of clock ticks per second: 100
d. Max number of open files: 1024
e. Size of a page: 4096 bytes
f. Total number of pages in physical memory: 3908526
g. Available pages in physical memory: 735201
               
 [~/Desktop/SSII/5]
 base  diksha  
 */
