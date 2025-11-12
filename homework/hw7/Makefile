OBJECTS = 
CFLAGS = -gdwarf-4 -Wall -O3 --std=c11 -D _DEFAULT_SOURCE

LDLIBS= -l criterion -lm
CC=clang

EXECUTABLES=simple_test_ballot simple_test_precinct simple_test_precinct_map voter_file


all: ${EXECUTABLES}

simple_test_ballot: simple_test_ballot.c ballot.c

simple_test_precinct: simple_test_precinct.c ballot.c precinct.c growable_array.c

simple_test_precinct_map: simple_test_precinct_map.c ballot.c precinct.c growable_array.c precinct_map.c

voter_file: ballot.c precinct.c growable_array.c precinct_map.c voter_file.c

clean:
	rm -f ${EXECUTABLES}
	rm -rf *.dSYM *~ \#* *.o
	rm -f core* vgcore*
	rm -f hyde-park-0.csv
