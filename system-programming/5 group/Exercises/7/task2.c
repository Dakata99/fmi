/* */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <wait.h>

#include "../../../6 group/Exercises/syshdr.h"

int main(int argc, char* argv[])
{
    if (argc < 4) err_exit("NOT ENOUGH ARGUMENTS!");

    int fd = open(argv[3], O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (fd == -1) err_sys_exit("COULD NOT OPEN FILE ", argv[3]);

    pid_t pid = fork();

    if (pid == -1) err_sys_exit("COULD NOT FORK!");
    else if (pid == 0) // child
    {
        int status = execlp(argv[1], "", NULL);
        if (status == -1) err_sys_exit("[1] EXEC ERROR!");
    }
    else // parent
    {
        int status;
        wait(&status);

        if (!WIFEXITED(status)) printf("Command %s failed execution...", argv[1]);
        else 
        {
            char* msg = malloc(strlen(argv[1]));
            if (msg == NULL) err_exit("MALLOC ERROR!");
            strcpy(msg, argv[1]);

            int status = write(fd, msg, sizeof(msg));
            if (status == -1) err_sys_exit("WRITE ERROR!");
        }

        status = execlp(argv[2], "", NULL);
        if (status == -1) err_sys_exit("[2] EXEC ERROR!");
    }

    return 0;
}