# This makefile assumes C_INCLUDE_PATH and LIBRARY_PATH
# have been set when using MacOS
OBJECTS = 
CFLAGS = -g -Wall -O3 --std=c11
LDLIBS= -l criterion -lm
CC=clang

student_test_lab3: student_test_lab3.c lab3.c

clean:
	rm -f student_test_lab3
	rm -rf *.dSYM *~ \#*
	rm -fr backups testfile 
