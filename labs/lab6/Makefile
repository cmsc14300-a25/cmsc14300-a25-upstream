OBJECTS = 
CFLAGS = -g -Wall --std=c11
LDLIBS= -l criterion -lm
CC=clang

all: simple_test_garray

simple_test_garray: growable_array.c simple_test_garray.c

clean:
	rm -f simple_test_garray
	rm -rf *.dSYM *~ \#* core vg*core
