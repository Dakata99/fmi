/*
В текущия каталог се намира текстов файл XXX със следното съдържание: Let's go change the world!
Напишете какво ще има записано във файла и какво ще бъде изведено на стандартния изход като резултат
от изпълнението на дадения по-долу фрагмент от програма на С.

Solution:
    - in file - Let's goxxx_aaa the world!\n
    - output - Let's change  the 1234!\n
*/

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(void)
{
    int fdi, fdio, nb1, nb2;
    char buff[15];

    fdi = open("XXX", O_RDONLY);
    fdio = open("XXX", O_RDWR);

    nb1 = read(fdi, buff, 6); // Let's[space]
    write(1, buff, nb1); // Let's 

    lseek(fdi, 3, SEEK_CUR);
    nb1 = read(fdi, buff, 7); //

    lseek(fdio, -19, SEEK_END);
    write(fdio, "xxx", 3);

    write(1, buff, nb1);
    write(fdio, "_aaa", 4);
    
    nb2 = read(fdio, buff, 5);
    write(1, buff, nb2);
    write(1, "1234", 4);

    lseek(fdi, -2, SEEK_END);
    nb2 = read(fdi, buff, 2);
    write(1, buff, nb2);

    return 0;
}