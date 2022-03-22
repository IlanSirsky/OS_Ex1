OUTPUT = shell
CC = gcc
CFLAGS = -Wall -g
OBJ = shell.o


all: output

main.o: main.c shell.h
	$(CC) -c $(CFLAGS) main.c

shell.o: shell.c shell.h
	$(CC) -c $(CFLAGS) shell.c

output: main.o $(OBJ)
	$(CC) $(CFLAGS) -o $(OUTPUT) main.o $(OBJ)

.PHONY: all clean output

clean:
	rm -f *.o $(OUTPUT)