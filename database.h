/*
   database.h

   Header file for definitions of maximum amounts to be
   used in CD.c and any other .c files that may need it.

   By Ross van Heerden, 2015
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define CD_AMOUNT 100		/*Maximum amount of CD's*/
#define TITLE_LENGTH 40		/*Maximum length of title*/

/*
	 Typedefs
*/
typedef struct cd_type	cd_t;


/*
   Function prototypes
*/
void	print_cd(cd_t *c);
void	trim_string(char []);
void	enter(char []);
int		yesno(char []);
int 	read_int();
float	read_float();
void	read_string(char [], char [], int);
void	read_cd(cd_t *cd);


/*
	 Structures
*/
struct cd_type
{
	char 		title[TITLE_LENGTH + 1];
	char 		artist[TITLE_LENGTH + 1];
	int 		num_tracks;
	int 		album;		/*non-zero number is album, 0 is single*/
	float 	price;	
};

