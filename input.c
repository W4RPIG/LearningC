/*
  input.c

  All the functions that helps with the input of data into the program
  are in this file.

  By Ross van Heerden, 2015
*/
#include "database.h"

/*
   Function prototypes
*/
void	enter(char []);
int		yesno(char []);
int 	read_int();
float	read_float();
void	read_string(char [], char [], int);


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

