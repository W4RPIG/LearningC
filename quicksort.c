/*
	quicksort.c

	A program that sorts an array of integers using the quick sort algorithm

	By Ross van Heerden, 2015
*/
#include <stdio.h>

static void swap(int *num1, int *num2){
	int temp;
	temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

static void qsort(int v[], int i, int j){
	int pivot = v[i];
	int left = i;
	int right = j;
	
	
	if(pivot > v[right]){
		swap(&v[left], &v[right]);
		pivot = v[right];
		while(pivot > v[left])	left++;
		if(left == right) printf("left = right");
		swap(&v[left], &v[right]);
		pivot = v[left];
		printf("left: %d	right: %d	pivot: %d\n", left, right, pivot);
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

	qsort(arr, 0, 7);

	for(i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
		printf("%d\t",arr[i]);
	printf("\n");

	return 0;
}
