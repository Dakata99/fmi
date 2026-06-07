/*
Да се напише програма на С, която използвайки системни примитиви за работа с файлове, чете
последователно по един символ от файл, чието име е подадено като първи параметър и по един символ
от стандартния вход. Добавя прочетените символи, премахвайки символите '0' - '9', последователно
след края на файл, чието име е подадено като втори параметър (ако файлът не съществува, се създава).
Чете се до достигане на края на файла или до изчерпване на входния поток. 
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>

int main(int argc, char* argv[])
{
    if (argc < 3) return -1;

    int fd1 = open(argv[1], O_RDONLY),
        fd2 = open(argv[2], O_WRONLY | O_CREAT | O_APPEND, 0644);

    if (fd1 == -1 || fd2 == -1) return -1;

    char buff1, buff2;
    while (read(fd1, &buff1, 1) && read(STDIN_FILENO, &buff2, 1))
    {
        if (!(buff1 >= '0' && buff1 <= '9')) write(fd2, &buff1, 1);
        if (!(buff2 >= '0' && buff2 <= '9')) write(fd2, &buff2, 1);
    }

    close(fd1);
    close(fd2);

    return 0;
}