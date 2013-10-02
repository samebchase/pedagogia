CC=clang
OPTIONS=-g -std=c99

all: test/util.out test/array.out test/sort.out test/search.out test/singly-linked-list.out

linked-list.o: linked-list.h linked-list.c
	$(CC) $(OPTIONS) -c linked-list.c

util.o: util.c util.h
	$(CC) $(OPTIONS) -c util.c

array.o: array.h array.c util.o
	$(CC) $(OPTIONS) -c array.c

matrix.o: matrix.h matrix.c array.o
	$(CC) $(OPTIONS) -c matrix.c

sort.o: sort.h sort.c array.o
	$(CC) $(OPTIONS) -c sort.c

search.o: search.h search.c array.o
	$(CC) $(OPTIONS) -c search.c

test/singly-linked-list.out: test/singly-linked-list.test.c linked-list.o
	$(CC) $(OPTIONS) -o test/singly-linked-list.out linked-list.o test/singly-linked-list.test.c

test/util.out: test/util.test.c util.o array.o
	$(CC) $(OPTIONS) -o test/util.out util.o array.o test/util.test.c -lm

test/array.out: test/array.test.c array.o util.o
	$(CC) $(OPTIONS) -o test/array.out array.o util.o test/array.test.c -lm

test/sort.out: test/sort.test.c sort.o util.o array.o
	$(CC) $(OPTIONS) -o test/sort.out sort.o array.o util.o test/sort.test.c -lm

test/search.out: test/search.test.c search.o array.o util.o
	$(CC) $(OPTIONS) -o test/search.out search.o array.o util.o test/search.test.c -lm

clean:
	rm test/*.out *.o
