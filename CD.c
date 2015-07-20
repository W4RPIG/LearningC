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
int	yesno(char []);
int 	read_int();
float	read_float();
void	read_string(char [], char [], int);
void	trim_string(char []);


void output(char tit[TITLE_LENGTH], char art[TITLE_LENGTH], unsigned short no_tracks, int alb, float prce){
	printf("%-20s %-15s %-10hu %-5d %-6.2f\n", tit, art, no_tracks, alb, prce);
}

void enter(char prompt[]){
	printf("%s\n", prompt);
	printf("Press ENTER to exit program");
	getchar();
}

int yesno(char string[]){
	char	yn;
	printf("%s\n", string);
	yn = toupper(yn);
	do{
		printf("Please enter 'Y' or 'N': ");
		scanf("%s", &yn);
	}while(yn != 'Y' && yn != 'N');
	switch(yn){
		case 'y':
		case 'Y':
			return 1;
			break;

		case 'n':
		case 'N':
			return 0;
			break;
	}
	return 0;
}

int read_int(char prompt[]){
	int	i;

	printf("%s\n", prompt);
	scanf("%d", &i);

	return i;
}

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

void trim_string(char string[]){
	if(string[strlen(string) - 1] == '\n')
		string[strlen(string) - 1] = '\0';
}



int main()
{
	char 	title[CD_AMOUNT][TITLE_LENGTH + 1];
	char 	artist[CD_AMOUNT][TITLE_LENGTH + 1];
	unsigned short 	num_tracks[CD_AMOUNT];
	int 	album[CD_AMOUNT];		/*non-zero number is album, 0 is single*/
	int 	ent_num, loop_num;
	float 	price[CD_AMOUNT];
	char	cont = 'Y';

	
	for(ent_num = 0; toupper(cont) == 'Y' && ent_num < CD_AMOUNT; ent_num++){
		/*
   		  Inputting data into title, artist, num_tracks, album and price variables.
		*/
		fputs("Please enter the CD's title: ", stdout);
		scanf("%[^\n]%*c", title[ent_num]);									/*%*c consumes the \n character at the end of the input and allows the next input to work correctly.*/
		trim_string(title[ent_num]);

#ifndef NOARTIST		
		fputs("Please enter the artist: ", stdout);
		scanf("%[^\n]%*c", artist[ent_num]);
		trim_string(title[ent_num]);
#endif

		fputs("Please enter the number of tracks on the CD: ", stdout);
		scanf("%hu", &num_tracks[ent_num]);

		{
		char album_or_single[TITLE_LENGTH + 1];

			for(;;){											/*Keep asking for Album or Single if neither is entered correctly.*/
				fputs("Please enter whether the CD is a \"Album\" or \"Single\": ", stdout);
				scanf("%s", album_or_single);
				if(!(strcmp("Album", album_or_single) && strcmp("Single", album_or_single))) break;
			}

			album[ent_num] = strcmp("Single", album_or_single);						/*Compares variable album_or_single with "Single" so variable album will be set to 1 if it does not match and 0 if it does*/
			if(album[ent_num]) album[ent_num] = 1;								/*Converts any non-zero number to 1 and leaves 0 as 0.*/
		}	

		fputs("Please enter the price (in Rands): ", stdout);
		scanf("%f", &price[ent_num]);

		fputs("Enter Y if there are more CD's: ", stdout);
		scanf(" %c%*c", &cont);
		/*if(!yesno("Enter Y if there are more CD's: ") break;*/
	}

		/*
		   Printing out the contents of the variables: title, artist, num_tracks, album and price.
		*/
		printf("%-20s %-15s %-10s %-5s %-6s\n", "Title", "Artist", "# Tracks", "Album", "Price");		
		/*
		   Making a heading for the variable so later I can print out a whole list of these variables when there is more than one CD.
		*/
		for(loop_num = 0; loop_num < ent_num ; loop_num++){
			output(title[loop_num], artist[loop_num], num_tracks[loop_num], album[loop_num], price[loop_num]);
		}


	
	return EXIT_SUCCESS;
}
