#include <stdio.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <stdlib.h>
#include <string.h>

#include "msg.h"

#define MODE    0600
#define MSG     "Hello, you s!ck..."

int main(void)
{  
    int id = msgget(IPC_PRIVATE, MODE | IPC_CREAT);
    if (id == -1) terminate("MSGGET ERROR!");

    msgbuf msg;
    msg.type = 1;
    msg.len = strlen(MSG);
    strcpy(msg.text, MSG);

    printf("TEXT = %s\nLength = %d\n", msg.text, msg.len);

    int status = snd_msg(id, &msg);
    if (status == -1) terminate(ERRMSGSND);

    msgbuf rcv;
    rcv.type = 1;

    int length = rcv_msg(id, &rcv);
    if (length == -1) terminate(ERRMSGRCV);

    printf("MSG = %s\nLength = %d\n", rcv.text, length);

    status = msgctl(id, IPC_RMID, NULL);
    if (status == -1) terminate(ERRMSGCTL);

    return 0;
}