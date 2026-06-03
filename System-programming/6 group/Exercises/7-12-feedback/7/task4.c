#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

#define USER   0
#define SYSTEM 1

void terminate(char* err, int type)
{
    if (type == SYSTEM) perror(err);
    else printf("%s", err);

    exit(EXIT_FAILURE);
}

void func(int sig)
{
    /* Can only use terminate("Catched SIGINT!\n", 0); instead the below */
    if (sig == SIGINT) printf("Catched SIGINT!\n");   /* този сигнал не е необходим в тази задача */

    kill(getpid(), SIGTERM);  /* малко пресилено и леко излишно да пращаш SIGTERM на собствения си процес */
}
/* може би не си разбрал правилно условието на задачата */
/* брояча не се увеличава през 1 секунда, а постоянно */
int main(void)
{
    for (int i = 0; ; i++)
    {
        printf("%d\n", i);
        sleep(1);
        if (signal(SIGINT, func) == SIG_ERR) terminate("SIGNAL ERROR!\n", SYSTEM);  /* защо signal() е в цикъл ?!? */
    }

    return 0;
}