#include	<stdio.h>
#include	<unistd.h>
#include	<stdlib.h>
#include	<string.h>

main ( int argc, char *argv [ ] )
{
	int fd , i, nbytr, nbytw, filesize = 0 ;
	char buf [ 25 ], str [ 5 ] ;

	close ( 0 );

	if ( (fd = open ( argv [1], O_RDONLY ) ) == -1 )
	{ write ( 2, "Cannot open file for reading \n",30 ); exit (1) ;  }

	while ( nbytr = read ( 0, buf, 25 )  )
	{
	  nbytw = write ( 1, buf, nbytr ) ;
	  if ( nbytr = nbytw ) filesize += nbytr ;
	  else 	write ( 2, "I/O Error! \n",  sizeof ( "I/O Error!\n" ) ) ;
	}
	write ( 1, "\nSize of file --> ",18 );
	sprintf ( str, "%d", filesize ) ;
	write ( 1, str, strlen ( str ) );
	write ( 1, " characters\n", 12 ); 

//	printf ("\nSize of file --> %d characters\n", filesize ); 
} 
