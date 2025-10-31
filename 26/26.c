/*
========================================================================================================
Name : 26.c
Author : Rinku Kumari Pareta
Description : Write a program to send messages to the message queue. Check $ipcs -q.
Date: 1 Oct, 2025.
========================================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct msgbuf {
    long mtype;
    char mtext[100];
};

int main() {
    key_t key = 1234;   
    int msgid = msgget(key, 0666 | IPC_CREAT);
    if (msgid == -1) {
        perror("msgget");
        exit(1);
    }

    struct msgbuf message;
    message.mtype = 1;

    printf("Enter your message: ");
    fgets(message.mtext, sizeof(message.mtext), stdin);

    if (msgsnd(msgid, &message, sizeof(message.mtext), 0) == -1) {
        perror("msgsnd");
        exit(1);
    }

    printf("Message sent to queue (key=%d, id=%d)\n", key, msgid);
    return 0;
}

/*
Output:
Terminal 1 :
base  diksha  cd ~/Desktop/SSII/26
               
 [~/Desktop/SSII/26]
 base  diksha  gcc 26.c -o 26      
               
 [~/Desktop/SSII/26]
 base  diksha  ./26
Enter your message: rinku
Message sent to queue (key=1234, id=1)
               
 [~/Desktop/SSII/26]

Terminal2:
 base  diksha  cd ~/Desktop/SSII/26
               
 [~/Desktop/SSII/26]
 base  diksha  gcc 26.c -o 26      
               
 [~/Desktop/SSII/26]
 base  diksha  ./26                
Enter your message: 
Message sent to queue (key=1234, id=1)
               
 [~/Desktop/SSII/26]
 base  diksha  ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages    
0x780834eb 0          diksha     666        100          1           
0x000004d2 1          diksha     666        200          2           


*/
