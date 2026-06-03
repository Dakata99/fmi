#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <wait.h>

#define MSG "Writing...\n"
#define COUNT 10
#define WRITE_END 1
#define READ_END 0

void terminate(char* err) { perror(err); exit(EXIT_FAILURE); }

int main(int argc, char* argv[])
{
    int file_des[2];

    pipe(file_des);

    pid_t pid = fork();
    if (pid == -1) terminate("Could not fork!\n");
    else if (pid == 0)
    {
        close(file_des[WRITE_END]); // close unused write end

        char buff;
        while (read(file_des[READ_END], &buff, sizeof(buff)))
        {
            write(STDOUT_FILENO, &buff, sizeof(buff));
            fflush(stdout);
        }

        close(file_des[READ_END]);
    }
    else
    {
        close(file_des[READ_END]); // close unused read end

        for (int i = 0; i < argc; i++)
        {
            write(file_des[WRITE_END], argv[i], sizeof(argv[i]));
            sleep(1);
        }
        
        int status;
        wait(&status);

        if (WIFEXITED(status)) printf("Child exited with status: %d\n", WEXITSTATUS(status));

        close(file_des[WRITE_END]);
    }

    return 0;
}