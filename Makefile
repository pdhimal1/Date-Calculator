CFLAGS = -g -Wall
CC = gcc

objects = Main.o date.o

source: $(objects)
	$(CC) $(objects) -o getDate



Main.o: Main.c
date.o: date.c

.phony: clean

clean:
	rm getDate
	rm $(objects)

