OBJECTS = 
CFLAGS = -gdwarf-4 -Wall -O3 --std=c11 -D _DEFAULT_SOURCE

LDLIBS= -l criterion -lm
CC=clang

EXECUTABLES=test_hw8 simple_test_candidates election_main simple_test_ballot simple_test_precinct


all: ${EXECUTABLES}

test_hw8: ballot.c test_hw8.c candidates.c util.c precinct.c growable_array.c election.c record_election_results.c precinct_map.c voter_file.c

simple_test_candidates: simple_test_candidates.c candidates.c util.c

simple_test_ballot: simple_test_ballot.c ballot.c candidates.c util.c 

simple_test_precinct: ballot.c precinct.c growable_array.c candidates.c util.c election.c simple_test_precinct.c

election_main: ballot.c precinct.c precinct_map.c voter_file.c candidates.c util.c election.c growable_array.c record_election_results.c election_main.c


clean:
	rm -f ${EXECUTABLES}
	rm -rf *.dSYM *~ \#* *.o
	rm -f core* vgcore*
	rm -f hyde-park-0.csv
