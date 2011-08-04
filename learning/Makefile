CC=g++
CFLAGS=-g -Wall -pedantic

all: learning.o
	$(CC) $(CFLAGS) learning.o -o learning

learning.o: learning.cpp learning.h
	$(CC) $(CFLAGS) -c learning.cpp
	
clean:
	rm -rf learning.o learning