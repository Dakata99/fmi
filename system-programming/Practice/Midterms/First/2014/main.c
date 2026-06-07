#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <utmp.h>

#define ERROR    "Error\n"
#define FILE_ERR "Could not open file!\n"
#define ARGS_ERR "Not enought arguments!\n"
#define PROC_ERR "Could not create new process!\n"

void terminate(const char* err) { perror(err); exit(EXIT_FAILURE); }

void task1(int argc, char* argv[])
{
    if (argc < 2)
    {
        write(2, ARGS_ERR, strlen(ARGS_ERR));
        exit(EXIT_FAILURE);
    }

    close(STDIN_FILENO);  // close std input = 0
    close(STDERR_FILENO); // close std error = 2
    
    int fd1 = open(argv[1], O_RDONLY),              // 0
        fd2 = open(argv[1], O_WRONLY | O_APPEND);   // 2

    if (fd1 < 0 || fd2 < 0) { write(2, FILE_ERR, strlen(FILE_ERR)); exit(EXIT_FAILURE); }

    char buffer;
    int flag = 0;

    while (read(0, &buffer, sizeof(buffer)))
    {
        if (flag) write(1, &buffer, sizeof(buffer));
        else if (isdigit(buffer)) flag = 1;
        else write(2, &buffer, sizeof(buffer));
    }

    close(fd1);
    close(fd2);
}

void task2(int argc, char* argv[])
{
    if (argc < 2) { printf(ARGS_ERR); exit(EXIT_FAILURE); }

    struct utmp* info;
    setutent();
    info = getutent();

    while (info)
    {
        char* name = strdup(info->ut_user);
        if (strcmp((char*) info->ut_user, argv[1]) == 0) { printf("YES\n"); break; }
        printf("%32s\n", info->ut_user);
        info = getutent();
    }
    printf("NO\n");
}

int main(int argc, char* argv[])
{
    //task1(argc, argv);
    task2(argc, argv);

    return 0;
}