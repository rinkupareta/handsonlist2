/*
========================================================================================================
Name : 28.c
Author : Rinku Kumari Pareta
Description : Write a program to change the existing message queue permission (use msqid_ds structure).
Date: 1 Oct, 2025.
========================================================================================================
*/
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    key_t k = ftok(".", 'a');
    if (k == -1) { perror("ftok"); exit(1); }

    int msqid = msgget(k, IPC_CREAT | 0666);
    if (msqid == -1) { perror("msgget"); exit(1); }
    struct msqid_ds st;
    if (msgctl(msqid, IPC_STAT, &st) == -1) { perror("msgctl"); exit(1); }
    printf("Current access Permissions are: %o\n", st.msg_perm.mode);
    st.msg_perm.mode = 0777;
    if (msgctl(msqid, IPC_SET, &st) == -1) { perror("msgctl"); exit(1); }
    if (msgctl(msqid, IPC_STAT, &st) == -1) { perror("msgctl"); exit(1); }
    printf("New access Permissions are: %o\n", st.msg_perm.mode);

    return 0;
}

/*
Output:
ase  diksha  cd ~/Desktop/SSII/28
               
 [~/Desktop/SSII/28]
 base  diksha  gcc 28.c -o 28      
               
 [~/Desktop/SSII/28]
 base  diksha  ./28
Current access Permissions are: 666
New access Permissions are: 777
               
 [~/Desktop/SSII/28]
 base  diksha  

*/
