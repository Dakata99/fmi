#include <stdio.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>

#include "msg.h"

#define MODE    0600

void cleanup(int sig)
{ printf("Got signal %s\n", strsignal(sig)); }

int main(int argc, char* argv[])
{
    if (argc < 2) return -1;

    int msg_id = msgget(IPC_PRIVATE, MODE | IPC_CREAT | IPC_EXCL);
    if (msg_id == -1) terminate("msgget error!");

    pid_t pid = fork();
    if (pid == 0) // child
    {
        msgbuf msg;
        msg.type = 1;

        int length;
        while ((length = read(0, msg.text, MAXLINE)) > 0)
        {
            msg.len = length;
            snd_msg(msg_id, &msg);
        }
        msg.len = 0;
        snd_msg(msg_id, &msg);
    }
    else // parent
    {
        int fd = open(argv[1], O_WRONLY | O_CREAT | O_SYNC, 0644);    /* O_TRUNC */
        if (fd == -1) terminate("Could not open file!");

        msgbuf msg;
        msg.type = 1;
        
        int length;
        while ((length = rcv_msg(msg_id, &msg)) > 0)
        {
            if (write(fd, msg.text, msg.len) != length) terminate("Write error!");
            else if (length < 0) terminate("Write error!");
        }
        close(fd);
        msgctl(msg_id, IPC_RMID, NULL);
    }

    return 0;
}