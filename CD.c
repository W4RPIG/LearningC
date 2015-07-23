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

/*#define RMPRINTING*/
#define RMBLOCK

/*
   Function prototypes
*/
void	output(char [], char [], int, int, float);
void	enter(char []);
int		yesno(char []);
int 	read_int();
float	read_float();
void	read_string(char [], char [], int);
void	trim_string(char []);

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

/*
	 Typedefs
*/
typedef struct cd_type	cd_t;


/*
	output()
	
	Prints out values of title, artist, number of tracks, album and price
	that is passed in as parameters.
*/
void output(char tit[TITLE_LENGTH], char art[TITLE_LENGTH], int no_tracks, int alb, float prce){
	printf("%-20s %-15s %-10d %-5d %-6.2f\n", tit, art, no_tracks, alb, prce);
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

	printf("%s", prompt);
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
	printf("%s", prompt);
	scanf(" %[^\n]%*c", answer);
	trim_string(answer);
}


/*
	 read_cd

	 Read the input into the contents of CD
*/
cd_t read_cd(){
	 cd_t	 cd_ans;
	 char	 alb_sing[10];
	 read_string("Please enter the CD's title: ", cd_ans.title, sizeof cd_ans.title);
	 read_string("Please enter the artist: ", cd_ans.artist, sizeof cd_ans.artist);
	 cd_ans.num_tracks = read_int("Please enter the number of tracks on the CD: ");
	 for(;;){
	 		read_string("Please enter whether the CD is a \"Album\" or \"Single\": ", alb_sing, sizeof alb_sing);
			if(!(strcmp("Album", alb_sing) && strcmp("Single", alb_sing))) break;
	 }
	 if(strcmp("Single", alb_sing)){		  						/*set to 1 if it does not match and 0 if it does*/
				 	 cd_ans.album = 1;
	 }
	 else cd_ans.album = 0;

	 cd_ans.price = read_float("Please enter the price (in Rands): ");
	 return cd_ans;
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

	  cd[ent_num] = read_cd();
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
