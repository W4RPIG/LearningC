/*
	quicksort.c

	A program that sorts an array of integers using the quick sort algorithm

	By Ross van Heerden, 2015
*/
#include <stdio.h>
#include <stdlib.h>

static void swap(int *num1, int *num2){
	int temp;
	temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

static void my_qsort(int v[], int i, int j){
	int pivot;
	int p;
	int first = i;
	int last = j;
	
	if(i < j){
		pivot = i;

		while(i < j){
			while(v[i] <= v[pivot] && i < j) i++;
			while(v[j] > v[pivot]) j--;
			if(i<j) swap(&v[i], &v[j]);
		}
		swap(&v[j], &v[pivot]);
	
		my_qsort(v, first, j-1);
		my_qsort(v, j+1, last);
	}
}

int main()
{
	int arr[8] = {6, 2, 8, 3, 1, 5, 7, 4};
	int i;
	
	printf("Initial array: \n");
	for(i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
		printf("%d\t",arr[i]);
	printf("\n");

	my_qsort(arr, 0, 7);

	for(i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
		printf("%d\t",arr[i]);
	printf("\n");

	return 0;
}
