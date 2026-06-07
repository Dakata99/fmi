#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <wait.h>

#define MSG "Writing...\n"
#define COUNT 10

void terminate(char* err) { perror(err); exit(EXIT_FAILURE); }

int main(void)
{
    int file_des[2];

    pipe(file_des);

    pid_t pid = fork();
    if (pid == -1) terminate("Could not fork!\n");
    else if (pid == 0) // child, writes to pipe
    {
        close(file_des[0]); /* Close unsed read end */
        
        for (int i = 0; i < COUNT; i++) write (file_des[1], MSG, strlen(MSG));
        
        close(file_des[1]);
    }
    else /* Reads from pipe */
    {
        close(file_des[1]); /* Close unsed write end */

        char buff;
        while (read(file_des[0], &buff, sizeof(buff))) write(STDOUT_FILENO, &buff, sizeof(buff));

        // wait(NULL); // may be not neccessary

        close(file_des[0]);
    }

    return 0;
}