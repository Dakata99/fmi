#define	READ	0
#define	WRITE	1

#include	<stdio.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	<fcntl.h>
main(int argc, char *argv[] )
{ int fd[2];

	pipe (fd);
	if ( fork () != 0 )
	{  close( 0 );
	   dup ( fd [READ] );
	   close ( fd [READ] );
	   close ( fd [WRITE] );
	   execlp ( "wc","wc", "-l", 0 );
	}
	else
	{  close ( 1 );
	   dup ( fd [WRITE] );
	   close ( fd [READ] );
	   close ( fd [WRITE] );
	   execlp ( argv[1],argv[1], argv[2], 0 );
	}
}
