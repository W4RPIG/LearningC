CC=gcc
CFLAGS=-I.
DEPS = database.h
OBJ = main.o input.o output.o utils.o 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

CD: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)
