/*
========================================================================================================
Name : 17c.c
Author : Rinku Kumari Pareta
Description : Write a program to execute ls -l | wc.
              c. use fcntl
Date: 1 Oct, 2025.
========================================================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int main() {
    int fd[2];
    pipe(fd);

    if (fork() == 0) {
        close(fd[0]); 
        fcntl(fd[1], F_DUPFD, STDOUT_FILENO); 
        close(fd[1]);
        execlp("ls", "ls", "-l", NULL);
        perror("execlp ls");
        exit(1);
    } else {
        close(fd[1]);  
        fcntl(fd[0], F_DUPFD, STDIN_FILENO);  
        close(fd[0]);
        execlp("wc", "wc", NULL);
        perror("execlp wc");
        exit(1);
    }
    return 0;
}
/*
Output:
 base  diksha  gcc 17c.c -o 17c
               
 [~/Desktop/SSII/17]
 base  diksha  ./17c
total 60
-rwxrwxr-x 1 diksha diksha 16208 Sep 30 15:59 17a
-rw-rw-r-- 1 diksha diksha  1179 Sep 30 16:00 17a.c
-rwxrwxr-x 1 diksha diksha 16208 Sep 30 16:00 17b
-rw-rw-r-- 1 diksha diksha  1119 Sep 30 16:00 17b.c
-rwxrwxr-x 1 diksha diksha 16208 Sep 30 16:00 17c
-rw-rw-r-- 1 diksha diksha   890 Sep 30 14:18 17c.c
^C
               
 [~/Desktop/SSII/17]
 ✘ base  diksha  
 */
