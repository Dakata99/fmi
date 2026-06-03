/*
Като първи параметър на програма на С се подава съществуващ празен файл. Напишете какво ще има 
записано във файла и какво ще бъде изведено на стандартния изход като резултат от изпълнението
на дадения по-долу фрагмент от програма на С.

Solution:
    - output:
        exam2\n
        exam1\n
        $(output of who command)
    - in file: 
        exam4\n
        exam4\n
        exam4\n
        exam4\n
        $(ouput of pwd command)
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <wait.h>

int main(int argc, char* argv[])
{
    int fd = open(argv[1], O_RDWR);
    int status;
    
    if (fork()) // parent
    {
        wait(&status);
        dup(fd); // fd > 2
        write(1, "exam1\n", 6); // output: exam1\n
        execlp("who", "who", "-u", NULL); // output of who command (if successful)
        write(fd, "exam3\n", 6); // not reachable
    }
    else // child
    {
        close(1); // close STDOUT
        dup(fd); // fd = 1 = STDOUT
        write(2, "exam2\n", 6); // output: exam2\n
        for (int i = 0; i <= 3; i++) write(1, "exam4\n", 6); // writes to file 4 times exam4\n
        execlp("pwd", "pwd", NULL); // writes to file PWD
    }

    return 0;
}