OUTPUT = shell
CC = gcc
CFLAGS = -Wall -g
OBJ = shell.o server.o client.o


all: output server

main.o: main.c shell.h
	$(CC) -c $(CFLAGS) main.c

shell.o: shell.c shell.h
	$(CC) -c $(CFLAGS) shell.c

client.o: client.c shell.h
	$(CC) -c $(CFLAGS) client.c

server.o: server.c shell.h
	$(CC) -c $(CFLAGS) server.c

server: server.o
	$(CC) $(CFLAGS) server.o -o server
	
output: main.o $(OBJ)
	$(CC) $(CFLAGS) -o $(OUTPUT) main.o shell.o client.o

.PHONY: all clean output server

clean:
	rm -f *.o $(OUTPUT) server