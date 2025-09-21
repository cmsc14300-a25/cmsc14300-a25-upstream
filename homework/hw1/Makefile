OBJECTS = 
CFLAGS = -g -Wall -O3 --std=c11 -D _DEFAULT_SOURCE

LDLIBS= -l criterion -lm
CC=clang

all: add2 student_test_hw1

add2: hw1.c add2.c

student_test_hw1: student_test_hw1.c hw1.c

clean:
	rm -f add2 student_test_hw1
	rm -rf *.dSYM *~ \#* *.o .DS_STORE
