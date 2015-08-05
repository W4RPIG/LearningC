CC=gcc
CFLAGS=-I.
OBJ = quicksort.o test_quicksort.o 

test_quicksort: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)
