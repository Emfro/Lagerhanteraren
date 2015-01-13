# Makefile for Lagerhanteraraen
# Shortcuts:
CC = gcc
CFLAGS = -g -Wall -std=c99 -ggdb


# MAIN FILE
lager: 	lagerhantering.c
	$(CC) $(CFLAGS) lagerhantering.c -c

lagermain: lagermain.c lagerhantering.c
	$(CC) $(CFLAGS) lagerhantering.c lagermain.c -o lager

.PHONY: clean run tests

clean:
	rm -f lager *.o

run: lagermain
	./lager

lagerhantering.o: lagerhantering.c lagerhantering.h
	$(CC) $(CFLAGS) lagerhantering.c -c

tests: lagerhantering.o unittests.c
	$(CC) $(CFLAGS) unittests.c lagerhantering.o -o tests -lcunit

test : tests
	cat test.input | ./tests
