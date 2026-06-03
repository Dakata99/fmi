#include        <stdio.h>
#include        <stdlib.h>
#include        <unistd.h>
#include        <fcntl.h>
main (int argc, char * argv [ ] )
{ int fd, j, nb1;
  char buf [5];
        if ( fork ( ))
           { wait ( ) ; execlp ( "cat", "cat", "fileA.txt" , 0); 
           }
        else { j = dup ( 1 );
               fd = open ( argv [1], O_RDWR );
               nb1 = read ( 0, buf, 5 );
                     write ( j, buf, nb1 );
               nb1 = read ( fd, buf, 5 );
                     write ( 1, buf, nb1 );
                     write ( fd, "\n", 1 ) ; 
                     write ( fd, buf, nb1 );
                     write ( j, buf, 3 );
               close ( fd ); close ( j );       
               exit(0);
            }
}


fileA.txt  -> 0123456789