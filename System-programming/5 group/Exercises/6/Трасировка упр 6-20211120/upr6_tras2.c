#include        <stdio.h>
#include        <fcntl.h>
#include        <unistd.h>

main ( )
{
        int fd, k, nb;
        char buf [6];

        k = dup ( 0 );
        fd = open ( "fileB", O_RDWR );
        nb = read ( k, buf, 5 );
              write ( fd, buf, nb );
              lseek(fd,1, SEEK_CUR);
          nb = read ( fd, buf, 7 );
              write ( 1, buf, nb );
              nb = read ( 0, buf, 4 );
              write ( 1, buf, nb );
        close ( fd ); close ( k );
        write( 1,"\n",1 );
        execlp ( "cat", "cat", "fileB",0 );
}

fileB - It is a nice day!
stdin - this girl