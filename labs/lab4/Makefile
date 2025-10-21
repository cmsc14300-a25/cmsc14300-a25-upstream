# This makefile assumes C_INCLUDE_PATH and LIBRARY_PATH
# have been set when using MacOS

OBJECTS = 
CFLAGS = -g -Wall --std=c11
LDLIBS= -l criterion -lm
CC=clang

all: student_test_matrix print_test buggy_print

student_test_matrix: matrix.c student_test_matrix.c

print_test: matrix.c print_test.c

buggy_print: buggy_print.c matrix.c

clean:
	rm -f student_test_matrix print_test buggy_print
	rm -rf *.dSYM *~ \#* core vg*core
