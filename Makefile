CC=clang
OPTIONS=-g -Wall -pedantic -std=c99 -Wgnu-empty-initializer -Wzero-length-array

AR=arrays
L=lib
LL=linked-lists
SE=searching
SO=sorting
T=test
U=util

all: $(T)/util.out $(T)/array.out $(T)/sort.out $(T)/search.out $(T)/singly-linked-list.out


lib/util.o: $(U)/util.c $(U)/util.h
	$(CC) $(OPTIONS) -c $(U)/util.c -o $(L)/util.o

test/util.out: $(T)/util.test.c $(L)/util.o $(L)/array.o
	$(CC) $(OPTIONS) -o $(T)/util.out $(L)/util.o $(L)/array.o $(T)/util.test.c -lm

lib/linked-list.o: $(LL)/linked-list.h $(LL)/linked-list.c
	$(CC) $(OPTIONS) -c $(LL)/linked-list.c -o $(L)/linked-list.o

test/singly-linked-list.out: $(T)/singly-linked-list.test.c $(L)/linked-list.o
	$(CC) $(OPTIONS) -o $(T)/singly-linked-list.out $(L)/linked-list.o $(T)/singly-linked-list.test.c


lib/array.o: $(AR)/array.h $(AR)/array.c $(L)/util.o
	$(CC) $(OPTIONS) -c $(AR)/array.c -o $(L)/array.o

test/array.out: $(T)/array.test.c $(L)/array.o $(L)/util.o
	$(CC) $(OPTIONS) -o $(T)/array.out $(L)/array.o $(L)/util.o $(T)/array.test.c -lm


lib/sort.o: $(SO)/sort.h $(SO)/sort.c $(L)/array.o
	$(CC) $(OPTIONS) -c $(SO)/sort.c -o $(L)/sort.o

test/sort.out: $(T)/sort.test.c $(L)/sort.o $(L)/util.o $(L)/array.o
	$(CC) $(OPTIONS) -o $(T)/sort.out $(L)/sort.o $(L)/array.o $(L)/util.o $(T)/sort.test.c -lm


lib/search.o: $(SE)/search.h $(SE)/search.c $(L)/array.o
	$(CC) $(OPTIONS) -c $(SE)/search.c -o $(L)/search.o

test/search.out: $(T)/search.test.c $(L)/search.o $(L)/array.o $(L)/util.o
	$(CC) $(OPTIONS) -o $(T)/search.out $(L)/search.o $(L)/array.o $(L)/util.o $(T)/search.test.c -lm


clean:
	rm test/*.out lib/*.o
