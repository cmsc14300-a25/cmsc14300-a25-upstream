OBJECTS = 
CFLAGS = -g -Wall -O3 --std=c11 -D _DEFAULT_SOURCE
LDLIBS= -l criterion -lm
CC=clang

all: simple_test_task simple_test_task_manager scheduler_main

simple_test_task: simple_test_task.c task.c

simple_test_task_manager: simple_test_task_manager.c task_manager.c task.c

scheduler_main: scheduler.c task.c task_manager.c util.c scheduler_main.c

clean:
	rm -f simple_test_task simple_test_task_manager scheduler_main
	rm -rf *.dSYM *~ \#* *.o
	rm -rf core vgcore*
