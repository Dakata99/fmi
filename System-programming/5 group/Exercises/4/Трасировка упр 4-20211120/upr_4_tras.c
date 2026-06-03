#include        <stdio.h>
#include        <unistd.h>
#include        <stdlib.h>
#include        <fcntl.h>

main ( )
{int fdw, fd2,  nb1, nb2;
char buf[25], buff[10];

        fdw = open ( "fileBB", O_WRONLY |O_CREATO_TRUNC,0777);
        fd2 = open ( "fileBB", O_RDWR );

        write ( fdw, "Today is sunny day", 18 );

        lseek ( fd2, 9, SEEK_SET );
        nb1 =  read ( fd2, buf, 6 );
        write( 1, buf, nb1 ) ;

        nb1 =  read ( fd2, buff, 3 );

        lseek ( fdw, -9, SEEK_END );
        write ( fdw, "very good", 9 );
        write ( 1, "morning!", 8 );

        write( fdw, " ", 1 ) ;
        write( fdw, buff, nb1 ) ;
}

