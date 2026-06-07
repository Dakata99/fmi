/* Read from stdin and write to queue */

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

msgbuf msg;

void sender(int msg_id)
{
    int n;
    msg.type = 1;
    while ((n = read(0, msg.text, MAXLINE)) > 0)
    {
        msg.len = n;
        snd_msg(msg_id, &msg);
        sleep(5); // uncomment this for seeing the delay and let MAXLINE be, for example 2, to see the output by 2 characters
    }

    if (n < 0) terminate("error 1!");

    msg.len = 0;
    snd_msg(msg_id, &msg);
}

int main(void)
{
    /* Open the message queue */
    int msg_id = msgget(MSG_KEY, 0);
    if (msg_id == -1) terminate(ERRMSGGET);

    sender(msg_id);

    return 0;
}