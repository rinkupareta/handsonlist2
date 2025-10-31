/*
========================================================================================================
Name : 22.c
Author : Rinku Kumari Pareta
Description : Wait for data on FIFO for 10 seconds using select().
Date : 1 Oct, 2025
========================================================================================================
*/
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/select.h>
#include <errno.h>

int main() {
    const char *fifo = "myfifonew"; 
    char buffer[100];

    if (access(fifo, F_OK) == -1) {
        if (mkfifo(fifo, 0666) == -1) {
            perror("mkfifo");
            exit(1);
        }
    }
    int fd = open(fifo, O_RDONLY | O_NONBLOCK);
    if (fd == -1) {
        perror("open fifo");
        exit(1);
    }

    printf("Waiting for data on FIFO '%s' for 10 seconds...\n", fifo);

    fd_set read_fds;        
    FD_ZERO(&read_fds);     
    FD_SET(fd, &read_fds);  

    struct timeval timeout;
    timeout.tv_sec = 10;
    timeout.tv_usec = 0;

    int r = select(fd + 1, &read_fds, NULL, NULL, &timeout);

    if (r == -1) {
        perror("select");
    } else if (r == 0) {
        printf("No data received in 10 seconds.\n");
    } else {
        if (FD_ISSET(fd, &read_fds)) {
            int n = read(fd, buffer, sizeof(buffer) - 1);
            if (n > 0) {
                buffer[n] = '\0';
                printf("Received: %s\n", buffer);
            } else if (n == 0) {
                printf("Writer closed FIFO (no data).\n");
            } else {
                perror("read");
            }
        }
    }
    close(fd);
    return 0;
}
/*
Output:
Terminal 1:
base  diksha  cd ~/Desktop/SSII/22
               
 [~/Desktop/SSII/22]
 base  diksha  gcc 22.c -o 22      
               
 [~/Desktop/SSII/22]
 base  diksha  ./22
Waiting for data on FIFO 'myfifonew' for 10 seconds...
Received: hello rinku

Terminal 2:
base  diksha  cd ~/Desktop/SSII/22
               
 [~/Desktop/SSII/22]
 base  diksha  gcc 22.c -o 22      
               
 [~/Desktop/SSII/22]
 base  diksha  echo "hello rinku"> myfifonew
               
 [~/Desktop/SSII/22]
*/
