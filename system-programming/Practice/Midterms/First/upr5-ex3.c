#include	<stdio.h>
#include	<unistd.h>
#include	<stdlib.h>

main ( )
{
	int fd, i, j, k ;

	if (  ( fd = creat ( "abc" , 0666 ) ) == -1 ) 
	{ write ( 2, "Cannot create file abc \n",24 ); exit (1) ;  }

	close ( 1 );
	k = dup ( fd ) ;

	for ( i = 0; i <= 15 ; ++i )
	   printf ( "i = %d\n", i );
} 
