/*
========================================================================================================
Name : 23.c
Author : Rinku Kumari Pareta
Description : Write a program to print the maximum number of files that can be opened within a process and size of a pipe (circular buffer).
Date: 1 Oct, 2025.
========================================================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    long pipeSize, maxFiles;
    pipeSize = pathconf(".", _PC_PIPE_BUF);
    if (pipeSize == -1) {
        perror("pathconf");
        exit(1);
    }
    maxFiles = sysconf(_SC_OPEN_MAX);
    if (maxFiles == -1) {
        perror("sysconf");
        exit(1);
    }

    printf("Size of pipe is : %ld bytes\n", pipeSize);
    printf("Maximum number of files that can be opened = %ld\n", maxFiles);

    return 0;
}
/*Output:

base  diksha  cd ~/Desktop/SSII/23
               
 [~/Desktop/SSII/23]
 base  diksha  gcc 23.c -o 23
               
 [~/Desktop/SSII/23]
 base  diksha  ./23    
Size of pipe is : 4096 bytes
Maximum number of files that can be opened = 1024
               
 [~/Desktop/SSII/
*/
