/*
 * CMSC 14300
 * Autumn 2025
 * Homework #5: Task manager implementation
 *
 * You will modify this file.
 */

#include "task_manager.h"

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "task.h"

/* Note: you are required to implement a specific form of linked list
 * for representing the tasks in the task manager.  See the assignment
 * writeup for details.
 */

// Do NOT copy these structures into a another file or create a new structures
// like these as a way to get around the opaque nature of these types.

/* Singly-linked list with a dummy head node */
struct dsll {
  task_t *task;
  struct dsll *next;
};

struct task_manager {
    unsigned int num_active;
    unsigned int num_finished;
    struct dsll *next;
};

/**** Add helper functions here ****/

/**** Required functions ****/

/* tm_create -- see task_manager.h for header comment */
task_manager_t *tm_create(void) {
  // TODO: complete this function and replace the return value
  // with an appropriate value;
  return NULL;
}

/* tm_free -- see task_manager.h  for header comment */
void tm_free(task_manager_t *tm) {
  // TODO: complete this function
}

/* tm_add_task -- see header file for header comment */
void tm_add_task(task_manager_t *tm, task_t *task) {
  assert(tm != NULL);

  // TODO: complete this function
}

/* tm_print: see task_manager.h for the header comment */
void tm_print(task_manager_t *tm) {
  assert(tm != NULL);

  // TODO: complete this function
}

/* tm_count_task_status -- see task_manager.h  for header comment */
void tm_count_task_status(task_manager_t *tm,
                                  unsigned int *num_active,
                                  unsigned int *num_finished) {
  assert(tm != NULL);

  // TODO: complete this function 
}


/* tm_run_cycle: see task_manager.h for the header comment */
// leave empty tasks in place.
unsigned int tm_run_cycle(task_manager_t *tm, unsigned int time_slice) {
  assert(tm != NULL);
  // TODO: complete this function and replace the return value
  // with an appropriate value;

  return 0;
}

/* tm_drop_finished: see task_manager.h for the header comment */
unsigned int tm_drop_finished(task_manager_t *tm) {
  assert(tm != NULL);

  // TODO: complete this function and replace the return value
  // with an appropriate value;
  return 0;
}
