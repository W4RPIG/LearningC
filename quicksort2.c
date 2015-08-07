/*
	quicksort2.c

	A program that sorts and array of integers using the quick sort algorithm
	Using pointers void pointers and function pointers

	By Ross van Heerden, 2015
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int comp_int(void *a, void *b)
{	
	return *((int*)a) - *((int*)b);
}

/*
	swap()

	swaps the address of the first two pointers of whos size is given in the
	third parameter
*/
static void swap(void *from, void *to, int size)
{
	void *temp = to;
	/*memcpy(temp, to, size);*/
	memcpy(to, from, size);
	memcpy(from, temp, size);
}


void my_qsort2(void *v[], int left, int right, int (*compare)(void *, void *))
{
	int pivot, first = left, last = right;
	

	if(left < right){
		pivot = left;

		while(left < right){
			printf("Left: %d	Right: %d\n", left, right);
			/*while(compare(&v[left], &v[right]) <= 1 && left < right) left++;
			while(compare(v[right], v[pivot]) > 1) right--;
			if(left < right) swap(&v[left], &v[right], sizeof(&v[left]));*/
		}
		swap(&v[right], &v[pivot], sizeof(&v[right]));
	
		my_qsort2(v, first, right-1, compare);
		my_qsort2(v, right+1, last, compare);
	}
}

int main()
{
	int (*comp)(void *, void *) = comp_int;
	int int_arr[] = {6, 3, 5, 2, 1, 7, 9, 8, 4};
	int i;
	
	my_qsort2((void *)int_arr, 0, sizeof(int_arr), comp);

	for(i = 0; i < sizeof(int_arr)/sizeof(int_arr[0]); i++){
		printf("%d ", int_arr[i]);
	}
	printf("\n");

	return 0;
}
