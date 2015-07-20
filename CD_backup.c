/*
   CD.c

   The course project program of C tutorials on YouTube which will store infomation
   on CD's and will have many other things continually added to it.

   by Ross van Heerden, 2015
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char 	title[41];
	char 	artist[41];
	unsigned short 	num_tracks;
	int 	album;											/*non-zero number is album, 0 is single*/
	float 	price;

	/*
   	  Inputting data into title, artist, num_tracks, album and price variables.
	*/
	printf("Please enter the CD's title: ");
	scanf("%[^\n]%*c", title);									/*%*c consumes the \n character at the end of the input and allows the next input to work correctly.*/
	
	printf("Please enter the artist: ");
	scanf("%[^\n]%*c", artist);

	printf("Please enter the number of tracks on the CD: ");
	scanf("%hu", &num_tracks);

	{
	char album_or_single[41];

		for(;;){										/*Keep asking for Album or Single if neither is entered correctly.*/
			printf("Please enter whether the CD is a \"Album\" or \"Single\": ");
			scanf("%s", album_or_single);
			if(!(strcmp("Album", album_or_single) && strcmp("Single", album_or_single))) break;
		}

		album = strcmp("Single", album_or_single);						/*Compares variable album_or_single with "Single" so variable album will be set to 1 if it does not match and 0 if it does*/
		if(album) album = 1;									/*Converts any non-zero number to 1 and leaves 0 as 0.*/
	}	

	printf("Please enter the price (in Rands): ");
	scanf("%f", &price);

	/*
	   Printing out the contents of the variables: title, artist, num_tracks, album and price.
	*/
	printf("%-20s %-15s %-10s %-5s %-6s\n", "Title", "Artist", "# Tracks", "Album", "Price");	/*Making a heading for the variable so later I can print out a whole list of these variables when there is more than one CD.*/
	printf("%-20s %-15s %-10hu %-5d %-6.2f\n", title, artist, num_tracks, album, price);

	return EXIT_SUCCESS;
}
