CFLAGS = -g -Wall -O0 --std=c11
LDLIBS=
LDFLAGS=-lm
CC=clang
EXECUTABLES= array_bounds array_pointer square strings array_of_strings string_length pointers_and_arrays_of_struct

all: $(EXECUTABLES)

%.o : %.c
	$(CC) -c $(CFLAGS) $< -o $@

%: %.o
	$(CC) $< -o $@ $(LDFLAGS)

clean:
	rm -f *.o *~
	rm -rf *dSYM
	rm -f ${EXECUTABLES}
