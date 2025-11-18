# This makefile assumes C_INCLUDE_PATH and LIBRARY_PATH
# have been set when using MacOS

OBJECTS = 
CFLAGS = -g -Wall --std=c11 -D _DEFAULT_SOURCE
LDLIBS= -l criterion -lm
CC=clang

all: simple_test_garray_extensions add_columns

simple_test_garray_extensions: growable_array.c simple_test_garray_extensions.c

add_columns: add_columns.c add_columns_main.c
	${CC} ${CFLAGS} add_columns.c add_columns_main.c ${LDFLAGS} -pthreads -o add_columns

clean:
	rm -f simple_test_garray_extensions add_columns
	rm -rf *.dSYM *~ \#* core vg*core
