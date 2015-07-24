/*
  Any untilities used in the CD program that have no home live here.

  By Ross van Heerden, 2015
*/
#include "database.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
	trim_string()

	Removes the new-line character from the end of a string, if one exists
*/
void trim_string(char string[]){
	if(string[strlen(string) - 1] == '\n')
		string[strlen(string) - 1] = '\0';
}


