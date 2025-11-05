OBJECTS = 
CFLAGS = -g -Wall -O3 --std=c11 -D _DEFAULT_SOURCE
LDLIBS= -l criterion -lm
CC=clang
EXECUTABLES=simple_test_task_manager scheduler_main simple_test_task_pq check_task_extra

all: ${EXECUTABLES}

check_task_extra: check_task_extra.c task.c

simple_test_task_pq: simple_test_task_pq.c task.c task_pq.c util.c growable_array.c

simple_test_task_manager: simple_test_task_manager.c task_manager.c task.c task_pq.c growable_array.c

scheduler_main: scheduler.c task.c task_manager.c util.c scheduler_main.c task_pq.c growable_array.c

clean:
	rm -f ${EXECUTABLES}
	rm -rf *.dSYM *~ \#* *.o
	rm -rf core vgcore*
