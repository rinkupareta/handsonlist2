/* 1
========================================================================================================
Name : 19d.c
Author : Rinku Kumari Pareta
Description : Create a FIFO file by
              d. mknod system call
Date: 1 Oct, 2025.
========================================================================================================
*/
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    if (mknod("fifo_mknod", S_IFIFO | 0666, 0) == -1) {
        perror("mknod");
        exit(1);
    }
    printf("FIFO 'fifo_mknod' created using mknod().\n");
    return 0;
}
/*
Output:

base  diksha  cd ~/Desktop/SSII/19
               
 [~/Desktop/SSII/19]
 base  diksha  gcc 19d.c -o 19d  
               
 [~/Desktop/SSII/19]
 base  diksha  ./19d
FIFO 'fifo_mknod' created using mknod().
               
 [~/Desktop/SSII/19]
 base  diksha  ls -l              
total 24
-rwxrwxr-x 1 diksha diksha 16080 Oct  1 02:54 19d
-rw-rw-r-- 1 diksha diksha   604 Oct  1 02:52 19d.c
-rw-rw-r-- 1 diksha diksha   604 Oct  1 02:53 19e.c
prw-rw-r-- 1 diksha diksha     0 Oct  1 02:54 fifo_mknod
               
 [~/Desktop/SSII/19]
 base  diksha  

*/
