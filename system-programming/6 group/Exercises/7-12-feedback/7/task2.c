#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "../syshdr.h"

#define SYSTEM 1

void terminate(char* err, int type)
{
    if (type == SYSTEM) perror(err);
    else printf("%s", err);

    exit(EXIT_FAILURE);
}

void func(int sig) { printf("CAUGHT SIGNAL = %s\n", strsignal(sig)); }

int main(void)
{
    int fds[2];

    if (pipe(fds) == -1) err_sys_exit("PIPE ERROR!\n");

    close(fds[0]); // READ FD

    char* msg = "Hello\n";

    if (signal(SIGPIPE, func) == SIG_ERR) terminate("SIGNAL ERROR!\n", 1);  /* трябва да подадеш указател към функция */
    
    (void) write(fds[1], msg, sizeof(msg));

    close(fds[1]);

    printf("HERE\n");
    (void) write(STDOUT_FILENO, msg, sizeof(msg));

    return 0;
}