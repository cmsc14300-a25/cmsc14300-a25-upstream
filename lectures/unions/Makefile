CFLAGS = -g -Wall -O0 --std=c11
LDLIBS=
LDFLAGS=-lm
CC=clang
EXECUTABLES= enum_example union_ex circle shape

all: $(EXECUTABLES)

%.o : %.c
	$(CC) -c $(CFLAGS) $< -o $@

%: %.o
	$(CC) $< -o $@ $(LDFLAGS)

clean:
	rm -f *.o *~
	rm -rf *dSYM
	rm -f ${EXECUTABLES}
