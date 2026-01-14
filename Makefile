CC=gcc


CFLAGS=-Wall -Wextra -g

all: LRanalyzer

LRanalyzer: LRanalyzer.o read_file.o LRGrammar.o Stack.o Tree.o
	$(CC) $(CFLAGS) -o LRanalyzer LRanalyzer.o read_file.o LRGrammar.o Stack.o Tree.o

LRanalyzer.o: LRanalyzer.c read_file.h Stack.h Tree.h
	$(CC) $(CFLAGS) -c LRanalyzer.c

read_file.o: read_file.c read_file.h LRGrammar.h
	$(CC) $(CFLAGS) -c read_file.c

LRGrammar.o: LRGrammar.c LRGrammar.h
	$(CC) $(CFLAGS) -c LRGrammar.c

Stack.o: Stack.c Stack.h Tree.h
	$(CC) $(CFLAGS) -c Stack.c

Tree.o: Tree.c Tree.h
	$(CC) $(CFLAGS) -c Tree.c

clean:
	rm -f *.o LRanalyzer