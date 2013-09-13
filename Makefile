CC=clang
OPTIONS=-g

util.o: util.c util.h
	$(CC) $(OPTIONS) -c util.c

array.o: array.h array.c util.o
	$(CC) $(OPTIONS) -c array.c

matrix.o: matrix.h matrix.c array.o
	$(CC) $(OPTIONS) -c matrix.c