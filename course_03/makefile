.PHONY: dirs clean

CC = gcc
OBJ = obj/linked_list.o

all: bin/main

bin/main: main.c $(OBJ)
	$(CC) -o $@ $< $(OBJ)

obj/%.o: %.c %.h
	$(CC) -c $< -o $@

dirs:
	mkdir -p bin obj

clean:
	rm -r bin obj
