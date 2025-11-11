OBJECTS = 
CFLAGS = -gdwarf-4 -Wall -O3 --std=c11 -D _DEFAULT_SOURCE

LDLIBS= -l criterion -lm
CC=clang

all: lab7_main simple_test_ballot

lab7_main: lab7_main.c lab7.c growable_array.c

simple_test_ballot: simple_test_ballot.c lab7.c growable_array.c

clean:
	rm -f lab7_main simple_test_ballot
	rm -rf *~ *.dSYM code vgcore*

