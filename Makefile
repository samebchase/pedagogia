CC=clang
OPTIONS=-g

util.o: util.c util.h
	$(CC) $(OPTIONS) -c util.c

array.o: array.h array.c util.o
	$(CC) $(OPTIONS) -c array.c

matri.o: matrix.h matrix.c array.o
	$(CC) $(OPTIONS) -c matrix.c

test/array.out: test/array.test.c array.o
	$(CC) $(OPTIONS) -o test/array.out test/array.test.c array.o
