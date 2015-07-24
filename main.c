/*
  main.c

  contains the main method for the CD program

  By Ross van Heerden, 2015
*/
#include "database.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int main()
{
	int 		ent_num, loop_num;
	cd_t		cd[CD_AMOUNT];

	/*Inputting data into title, artist, num_tracks, album and price variables belonging to cd.*/
	for(ent_num = 0; ent_num < CD_AMOUNT; ent_num++){		
			cd[ent_num] = read_cd();
			if(!yesno("Enter Y if there are more CD's: ")) break;
	}

		/*
		   Printing out the contents of the variables: title, artist, num_tracks, album and price.
		*/
		printf("%-20s %-15s %-10s %-5s %-6s\n", "Title", "Artist", "# Tracks", "Album", "Price");		
		for(loop_num = 0; loop_num <= ent_num ; loop_num++){
			print_cd(cd[loop_num]);
		}

	return EXIT_SUCCESS;
}
