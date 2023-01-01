CC = gcc
FLAGS = -Wall -g

all: isort txtfind

txtfind: txtfind.o
	$(CC) $(FLAGS) txtfind.o -o txtfind
isort: isort.o 
	$(CC) $(FLAGS) isort.o -o isort
	
isort.o: isort.c
	$(CC) $(FLAGS) -c isort.c

txtfind.o: txtfind.c header.h
	$(CC) $(FLAGS) -c txtfind.c 

.phony: clean all	

clean: 
	rm -f *.o isort txtfind
