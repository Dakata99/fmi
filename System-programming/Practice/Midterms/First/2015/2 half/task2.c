/*
В текущия каталог се намира текстов файл abc със следното съдържание: Let's go change the world!
Напишете какво ще има записано във файла и какво ще бъде изведено на стандартния изход като резултат
от изпълнението на дадения по-долу фрагмент от програма на С.
*/

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(void)
{
    int fdi, fdio, nb1, nb2;
    char buff[15];
    
    fdi = open("abc", O_RDONLY);
    fdio = open("abc", O_RDWR);

    nb1 = read(fdi, buff, 6); // nb1 = 6, buff = Let's[space]
    write(1, buff, nb1); // Let's 

    lseek(fdi, 3, SEEK_CUR);
    nb1 = read(fdi, buff, 6); // nb1 = 6, buff = change

    lseek(fdio, -19, SEEK_END);
    write(fdio, "xxxx", 4);

    write(1, buff, nb1); // change
    write(fdio, "_123_", 5);

    lseek(fdio, 2, SEEK_CUR);
    nb2 = read(fdio, buff, 6); // nb2 = 6, buff = [space]world
    write(1, buff, nb2); // [space]world
    write(1, "_abcd", 5);

    lseek(fdi, -2, SEEK_END);
    nb2 = read(fdi, buff, 2); // nb2 = 2, buff = !\n
    write(1, buff, nb2); // !

    return 0;
}