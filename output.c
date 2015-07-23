/*
  output.c

  all output methods and function prototypes are here
  
  By Ross van Heerden, 2015
*/


/*
   Function prototypes
*/
#include "database.h"
void	output(char [], char [], int, int, float);



/*
	print_cd()
	
	Prints out values of title, artist, number of tracks, album and price
	that is passed in as parameters.
*/
void print_cd(cd_t cd){
	printf("%-20s %-15s %-10d %-5d %-6.2f\n", cd.title, cd.artist, cd.num_tracks, cd.album, cd.price);
}
