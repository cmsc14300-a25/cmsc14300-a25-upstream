OBJECTS = 
CFLAGS = -g -Wall -O3 --std=c11 -D _DEFAULT_SOURCE

LDLIBS= -l criterion -lm
CC=clang

all: student_test_ballot student_test_round election check_space

student_test_ballot: student_test_ballot.c ballot.c util.c

student_test_round: student_test_round.c round.c ballot.c util.c

election: round.c ballot.c util.c election.c

check_space: check_space.c ballot.c util.c

clean:
	rm -f student_test_ballot student_test_round election check_space
	rm -rf *.dSYM *~ \#* *.o
