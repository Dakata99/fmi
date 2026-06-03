/* Read from file, specified by argv[1], and write to queue */

#include <stdio.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#include "msg.h"

#define MODE    0600
#define COUNT   2

msgbuf msg;

void sender(int msg_id, const char* filename)
{
    char errmsg[MAXLINE];

    int fd = open(filename, O_RDONLY);
    if (fd == -1)
    {
        sprintf(errmsg, ": can't open: %s\n", strerror(errno));
        strcat(msg.text, errmsg);
        msg.len = strlen(msg.text);
        snd_msg(msg_id, &msg);
    }
    else // file is open and read from it
    {
        int n;
        msg.type = 1;
        while ((n = read(fd, msg.text, COUNT)) > 0)
        {
            msg.len = n;
            snd_msg(msg_id, &msg);
            sleep(3); // uncomment this for seeing the delay and let MAXLINE be, for example 2, to see the output by 2 characters
        }

        close(fd);
        if (n < 0) terminate("error 1!");
    }
    msg.len = 0;
    snd_msg(msg_id, &msg);
}

int main(int argc, char* argv[])
{
    if (argc < 2) return -1;

    /* Open the message queue */
    int msg_id = msgget(MSG_KEY, IPC_CREAT | IPC_EXCL | MODE);
    if (msg_id == -1) terminate(ERRMSGGET);

    sender(msg_id, argv[1]);

    return 0;
}