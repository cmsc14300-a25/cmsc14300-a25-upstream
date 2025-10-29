/*
 * CMSC 14300
 * Autumn 2025
 * Homework #5: Task module implementation
 *
 * You will modify this file.
 */

#include "task.h"

#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Opaque type: this structure is defined here rather than in the
// header file to prevent clients from accessing the fields directly.
// Do NOT copy this structure into a another file or create a new one like it.
struct task {
  unsigned int tid;
  unsigned int priority;
  unsigned int running_time;
};

/* mk_task -- see task.h for header comment */
task_t *mk_task(unsigned int tid, unsigned int priority,
                unsigned int running_time) {
  // TODO: complete this function and replace the return value
  // with an appropriate value;
  return NULL;
}

/* free_task -- see task.h for header comment */
void free_task(task_t *task) {
  // TODO: complete this function
}

/* get_tid_task -- see task.h for header comment */
unsigned int get_tid_task(task_t *task) {
  assert(task != NULL);

  // TODO: complete this function and replace the return value
  // with an appropriate value;
  return 0;
}

/* get_priority_task -- see task.h for header comment */
unsigned int get_priority_task(task_t *task) {
  assert(task != NULL);

  // TODO: complete this function and replace the return value
  // with an appropriate value;
  return 0;
}

/* is_active -- see task.h for header comment */
bool is_active_task(task_t *task) {
  assert(task != NULL);

  // TODO: complete this function and replace the return value
  // with an appropriate value; 
  return false; 
}


/* print_task -- see task.h for header comment */
void print_task(task_t *task) {
  // TODO: complete this function
}

/* mk_task_from_line -- see task.h for header comment */
task_t *mk_task_from_line(char *line) {
  assert(line != NULL);
  // TODO: complete this function and replace the return value
  // with an appropriate value;
  return NULL;
}

/* run_task_slice -- see task.h for header comment */
bool run_task_slice(task_t *task, unsigned int time_slice,
                    unsigned int *time_used) {
  // TODO: complete this function and replace the return value
  // with an appropriate value;
  return false;
}
