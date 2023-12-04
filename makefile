all: myset

myset: myset.o set.o
	gcc -g -Wall -ansi -pedantic -o myset myset.o set.o

myset.o: myset.c set.h
	gcc -Wall -ansi -pedantic -c myset.c

set.o: set.c set.h
	gcc -Wall -ansi -pedantic -c set.c
