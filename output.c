/*
  output.c

  all output methods and function prototypes are here
  
  By Ross van Heerden, 2015
*/
#include "database.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
	print_cd()
	
	Prints out values of title, artist, number of tracks, album and price
	that is passed in as parameters.
*/
void print_cd(cd_t cd){
	printf("%-20s %-15s %-10d %-5d %-6.2f\n", cd.title, cd.artist, cd.num_tracks, cd.album, cd.price);
}
