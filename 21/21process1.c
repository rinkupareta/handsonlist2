/*
============================================================================
Name : 21process1.c
Author : Rinku Kumari Pareta
Description : Two-way communication using FIFO (process1 side).
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>

#define FIFO1 "fifo1"
#define FIFO2 "fifo2"

int main() {
    int fd1, fd2;
    char buffer[100];

    // Create FIFOs if they don’t exist
    mkfifo(FIFO1, 0666);
    mkfifo(FIFO2, 0666);

    while (1) {
        // Open FIFO1 for writing (P1 → P2)
        fd1 = open(FIFO1, O_WRONLY);
        printf("Process1: Enter message: ");
        fgets(buffer, sizeof(buffer), stdin);
        write(fd1, buffer, strlen(buffer)+1);
        close(fd1);

        // Open FIFO2 for reading (P2 → P1)
        fd2 = open(FIFO2, O_RDONLY);
        read(fd2, buffer, sizeof(buffer));
        printf("Process2 replied: %s\n", buffer);
        close(fd2);
    }

    return 0;
}

