/* 
========================================================================================================
Name : 19e.c
Author : Rinku Kumari Pareta
Description : Create a FIFO file by
              e. mkfifo library function
Date: 1 Oct, 2025.
========================================================================================================
*/
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    if (mkfifo("fifo_mkfifo", 0666) == -1) {
        perror("mkfifo");
        exit(1);
    }
    printf("FIFO 'fifo_mkfifo' created using mkfifo().\n");
    return 0;
}
/*
Output:

base  diksha  gcc 19e.c -o 19e
               
 [~/Desktop/SSII/19]
 base  diksha  ./19e
FIFO 'fifo_mkfifo' created using mkfifo().
               
 [~/Desktop/SSII/19]
 base  diksha  ls -l
total 40
-rwxrwxr-x 1 diksha diksha 16080 Oct  1 02:54 19d
-rw-rw-r-- 1 diksha diksha  1199 Oct  1 02:55 19d.c
-rwxrwxr-x 1 diksha diksha 16088 Oct  1 02:55 19e
-rw-rw-r-- 1 diksha diksha   601 Oct  1 02:55 19e.c
prw-rw-r-- 1 diksha diksha     0 Oct  1 02:55 fifo_mkfifo
prw-rw-r-- 1 diksha diksha     0 Oct  1 02:54 fifo_mknod
               
 [~/Desktop/SSII/19]
 base  diksha  
 
 */
