/*
В текущия каталог се намира текстов файл abc със следното съдържание: Let's go change the world!
Като първи параметър на програма на С се подава съществуващ празен файл. Напишете какво ще има 
записано във файла и какво ще бъде изведено на стандартния изход като резултат от изпълнението
на дадения по-долу фрагмент от програма на С.

Solution:
    - output:
        hello5 abc
    - in file:
        hello3\n
        hello4\n
*/

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <wait.h>

int main(int argc, char* argv[])
{
    if (argc < 2) return -1;

    int fd, status;
    if (fork()) // parent
    {
        wait(&status);
        for (int i = 0; i <= 3; i++)
        {
            write(1, "hello1\n", 5); // hello
            execlp("wc", "wc", "-w", "abc", NULL); // output of wc -w abc
            write(1, "hello2\n", 7); // not reachable
        }
    }
    else // child
    {
        close(1); // close 1
        fd = open(argv[1], O_RDWR); // fd = 1
        write(1, "hello3\n", 7);
    }
    write(1, "hello4\n", 7); // won't be reached by parent

    return 0;
}