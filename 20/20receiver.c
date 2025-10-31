/*
============================================================================
Name : 20receiver.c
Author : Rinku Kumari Pareta
Description : Reader program that receives data from sender using FIFO.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

#define FIFO_NAME "myfifo"

int main() {
    int fd;
    char buffer[100];

    // FIFO should already exist from sender
    fd = open(FIFO_NAME, O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(1);
    }

    // Read message from FIFO
    read(fd, buffer, sizeof(buffer));
    printf("Received: %s\n", buffer);

    close(fd);
    return 0;
}
/*
output:
terminal 2:

base  diksha  
               
 [~]
 base  diksha  cd ~/Desktop/SSII
               
 [~/Desktop/SSII]
 base  diksha  gcc 20sender.c -o sender
               
 [~/Desktop/SSII]
 base  diksha  gcc 20receiver.c -o receiver
               
 [~/Desktop/SSII]
 base  diksha  ./receiver
Received: rinku

*/        

