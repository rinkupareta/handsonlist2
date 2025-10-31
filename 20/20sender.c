/*
============================================================================
Name : 20sender.c
Author : Rinku Kumari Pareta
Description : Writer program that sends data to reader using FIFO.
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

    // Create FIFO (only once)
    if (mkfifo(FIFO_NAME, 0666) == -1) {
        perror("mkfifo");  // If already exists, shows error but continues
    }

    // Open FIFO for writing
    fd = open(FIFO_NAME, O_WRONLY);
    if (fd == -1) {
        perror("open");
        exit(1);
    }

    printf("Enter a message to send: ");
    fgets(buffer, sizeof(buffer), stdin);

    // Write message to FIFO
    write(fd, buffer, sizeof(buffer));

    close(fd);
    return 0;
}
/*
output:
terminal 1:

base  diksha  cd ~/Desktop/SSII       
               
 [~/Desktop/SSII]
 base  diksha  gcc 20receiver.c -o receiver
               
 [~/Desktop/SSII]
 base  diksha  gcc 20sender.c -o sender    
               
 [~/Desktop/SSII]
 base  diksha  ./sender  
mkfifo: File exists
rinku
               
*/
