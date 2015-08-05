/*
	test_quicksort.c

	A program that tests quicksort.c by reading in integers from
	a text file and prints its output.

	By Ross van Heerden, 2015
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
	FILE *fp;
	int num_ints, i = 0;
	char c;

	fp = fopen("numbers.txt", "r");
	if(fp == NULL){
		fprintf(stderr, "Cant open requested file\n");
		exit(1);
	}

	while((c = fgetc(fp)) != EOF){
		while(isspace(c)) fgetc(fp);
		num_ints++;		/*Run through file to see how many ints it contains.*/
		fgetc(fp);
		printf("%d\n", num_ints);
	}
	fclose(fp);
	
	/*second run through the txt file to read ints into array*/
	{
		int int_arr[num_ints];					/*Not allowed by IS0 90, what can I do to get around this?*/
		fp = fopen("numbers.txt", "r");
		while((c = fgetc(fp)) != EOF){
			while(isspace(c) && (c = fgetc(fp)) != EOF) fgetc(fp);
			int_arr[i++] = c;	
		}
		my_qsort(int_arr, 0, num_ints);
		fclose(fp);
		
		fp = fopen("numbers_result.txt", "a");
		/*printing results to text file:*/
		for(i = 0; i < num_ints; i++){
			fprintf(fp, "%d ", int_arr[i]);
		}
	}

	
	
	return 0;
}
