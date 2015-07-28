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
	/*static cd_t		cd[CD_AMOUNT];*/
	int			cd_amount = read_num_cds();

	cd_t *cd_p;
	cd_p = malloc(cd_amount * sizeof(cd_t));
	if(cd_p == NULL){
		printf("Malloc failed in main.c\n");
		exit(1);
	}

	/*Inputting data into title, artist, num_tracks, album and price variables belonging to cd.*/
	for(ent_num = 0; ent_num < cd_amount; ent_num++){	
			printf("=========CD %d==========\n",ent_num+1);
			read_cd(&cd_p[ent_num]);	
	}


		/*
		   Printing out the contents of the variables: title, artist, num_tracks, album and price.
		*/
		printf("%-20s %-15s %-10s %-5s %-6s\n", "Title", "Artist", "# Tracks", "Album", "Price");		
		for(loop_num = 0; loop_num < ent_num ; loop_num++){
			print_cd(&cd_p[loop_num]);
		}
		free(cd_p);
		return EXIT_SUCCESS;
}
