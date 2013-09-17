CC=clang
OPTIONS=-g

util.o: util.c util.h
	$(CC) $(OPTIONS) -c util.c

array.o: array.h array.c util.o
	$(CC) $(OPTIONS) -c array.c

matrix.o: matrix.h matrix.c array.o
	$(CC) $(OPTIONS) -c matrix.c

sort.o: sort.h sort.c array.o
	$(CC) $(OPTIONS) -c sort.c

test/array.out: test/array.test.c array.o util.o
	$(CC) $(OPTIONS) -o test/array.out test/array.test.c array.o util.o

test/sort.out: test/sort.test.c sort.o util.o array.o
	$(CC) $(OPTIONS) -o test/sort.out test/sort.test.c sort.o array.o util.o
