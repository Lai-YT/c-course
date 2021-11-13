.PHONY: dirs clean

CC = gcc
CFLAGS = -Wall
OBJ = obj/linked_list.o obj/read.o

all: bin/main

bin/main: main.c $(OBJ)
	$(CC) -o $@ $< $(OBJ) $(CFLAGS)

obj/%.o: %.c %.h
	$(CC) -c $< -o $@ $(CFLAGS)

dirs:
	mkdir -p bin obj

clean:
	rm -r bin obj
