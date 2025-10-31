/*
============================================================================
Name : 21process2.c
Author : Rinku Kumari Pareta
Description : Two-way communication using FIFO (process2 side).
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
        // Open FIFO1 for reading (P1 → P2)
        fd1 = open(FIFO1, O_RDONLY);
        read(fd1, buffer, sizeof(buffer));
        printf("Process1 said: %s\n", buffer);
        close(fd1);

        // Open FIFO2 for writing (P2 → P1)
        fd2 = open(FIFO2, O_WRONLY);
        printf("Process2: Enter reply: ");
        fgets(buffer, sizeof(buffer), stdin);
        write(fd2, buffer, strlen(buffer)+1);
        close(fd2);
    }

    return 0;
}

