#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void terminate(char* err) { perror(err); exit(EXIT_FAILURE); }

void write_file(void)
{
    int fd = open("aa", O_WRONLY | O_CREAT, 0644);
    if (fd < 0) terminate("Could not open file aa!\n");

    char letter = 'a';

    while (letter <= 'z') { write(fd, &letter, sizeof(letter)); letter++; }

    close(fd);
}

int main(void)
{
/* TASK 1 */
    write_file();

    int fd = open("aa", O_RDONLY);
    if (fd < 0) terminate("Could not open file aa!\n");

    char buffer[16];

    for (int i = 5; i >= 1; i--)
    {
        read(fd, buffer, sizeof(buffer));
        printf("%s\n", buffer);
        // write(1, buffer, sizeof(buffer)); // TASK 2
    }

/* TASK 1 */

    return 0;
}