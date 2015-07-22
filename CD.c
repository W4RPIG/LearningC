/*
   CD.c

   The course project program of C tutorials on YouTube which will store infomation
   on CD's and will have many other things continually added to it.

   by Ross van Heerden, 2015
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "database.h"

/*
   Function prototypes
*/
void	output(char [], char [], unsigned short, int, float);
void	enter(char []);
int		yesno(char []);
int 	read_int();
float	read_float();
void	read_string(char [], char [], int);
void	trim_string(char []);

struct cd_type
{
	char 		title[TITLE_LENGTH + 1];
	char 		artist[TITLE_LENGTH + 1];
	unsigned short 	num_tracks;
	int 		album;		/*non-zero number is album, 0 is single*/
	float 	price;	
};

typedef struct cd_type	cd_t;

/*
	output()
	
	Prints out values of title, artist, number of tracks, album and price
	that is passed in as parameters.
*/
void output(char tit[TITLE_LENGTH], char art[TITLE_LENGTH], unsigned short no_tracks, int alb, float prce){
	printf("%-20s %-15s %-10hu %-5d %-6.2f\n", tit, art, no_tracks, alb, prce);
}

/*
	enter()
	
	Print out string given to method as parameter.
	Print out "Press ENTER to exit program"
	Waits for user to press any button.
*/
void enter(char prompt[]){
	printf("%s\n", prompt);
	printf("Press ENTER to exit program");
	getchar();
}

/*
	yesno()

	Print out the string given to the method.
	Read in character from input.
	If character is 'Y' return 1, if 'N' return 0;
*/
int yesno(char string[]){
	char	yn;	
	for(;;){
		printf("%s", string);
		scanf(" %c", &yn);
		yn = toupper(yn);
		if(yn == 'Y')	return 1;
		if(yn == 'N') return 0;
	}
}

/*
	read_int()
	
	Print out string given to read_int() as a parameter.
	Read integer from input and return the value of this int.

*/
int read_int(char prompt[]){
	int	i;

	printf("%s\n", prompt);
	scanf("%d", &i);

	return i;
}

/*
	read_float()
	
	Print out string given to read_float() as a parameter.
	Read float from input and return the value of this float.
*/
float read_float(char prompt[]){
	float	f;

	printf("%s", prompt);
	scanf("%f", &f);

	return f;
}

/*
   read_string()

   Ask the user a question and prompt for a string answer.
   max = size of "answer" including the null terminating character.
   Note: the answer parameter is MODIFIED by the function
*/
void read_string(char prompt[], char answer[], int max){
	fputs(prompt, stdout);
	fflush(stdin);
	fgets(answer, max, stdin);

	trim_string(answer);
}

/*
	trim_string()

	Removes the new-line character from the end of a string, if one exists
*/
void trim_string(char string[]){
	if(string[strlen(string) - 1] == '\n')
		string[strlen(string) - 1] = '\0';
}



int main()
{
	int 		ent_num, loop_num;

	cd_t cd[CD_AMOUNT];
	
	for(ent_num = 0; ent_num < CD_AMOUNT; ent_num++){
		/*
   		  Inputting data into title, artist, num_tracks, album and price variables belonging to cd.
		*/
		fputs("Please enter the CD's title: ", stdout);
		scanf(" %[^\n]%*c", cd[ent_num].title);															/*%*c consumes the \n character at the end of the input and allows the next input to work correctly.*/
		trim_string(cd[ent_num].title);

#ifndef NOARTIST		
		fputs("Please enter the artist: ", stdout);
		scanf("%[^\n]%*c", cd[ent_num].artist);
		trim_string(cd[ent_num].title);
#endif

		fputs("Please enter the number of tracks on the CD: ", stdout);
		scanf("%hu", &cd[ent_num].num_tracks);

		{
		char album_or_single[TITLE_LENGTH + 1];

			for(;;){											/*Keep asking for Album or Single if neither is entered correctly.*/
				fputs("Please enter whether the CD is a \"Album\" or \"Single\": ", stdout);
				scanf("%s", album_or_single);
				if(!(strcmp("Album", album_or_single) && strcmp("Single", album_or_single))) break;
			}

			cd[ent_num].album = strcmp("Single", album_or_single);						/*Compares variable album_or_single with "Single" so variable album will be set to 1 if it does not match and 0 if it does*/
			if(cd[ent_num].album) cd[ent_num].album = 1;											/*Converts any non-zero number to 1 and leaves 0 as 0.*/
		}	

		fputs("Please enter the price (in Rands): ", stdout);
		scanf("%f", &cd[ent_num].price);

		if(!yesno("Enter Y if there are more CD's: ")) break;
	}

		/*
		   Printing out the contents of the variables: title, artist, num_tracks, album and price.
		*/
		printf("%-20s %-15s %-10s %-5s %-6s\n", "Title", "Artist", "# Tracks", "Album", "Price");		
		for(loop_num = 0; loop_num <= ent_num ; loop_num++){
			output(cd[loop_num].title, cd[loop_num].artist, cd[loop_num].num_tracks, cd[loop_num].album, cd[loop_num].price);
		}


	
	return EXIT_SUCCESS;
}
