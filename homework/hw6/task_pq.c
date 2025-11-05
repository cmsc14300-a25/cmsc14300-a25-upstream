/*
 * CMSC 14300
 * Autumn 2025
 * Homework #6: Task priority queue implementation
 *
 * You will modify this file.
 */

#include "task_pq.h"

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "growable_array.h"
#include "task.h"

#define INITIAL_HEAP_SIZE 5

/********* Do NOT modify this structure definition *********/
/********* Do NOT replicate it elsewhere *********/

/* Structure definition for the task priority queue */
struct task_pq {
  unsigned int num_tasks;
  garray_t* tasks;
};


/********* Helper functions *********/

// put your helper functions here.

/********* API functions *********/

/* task_pq_create -- see task_pq.h for the header comment */
task_pq_t *task_pq_create() {
  // TODO: complete this function and replace
  // the return value with an appropriate value.
  return NULL;
}

/* task_pq_free -- see task_pq.h for the header comment */
void task_pq_free(task_pq_t *tpq, bool should_free_tasks) {
  assert(tpq != NULL);

  // TODO: complete this function
}

/* task_pq_print -- see task_pq.h for the header comment */
void task_pq_print(task_pq_t *tpq) {
  assert(tpq != NULL);

  // OPTIONAL function
}

/* task_pq_is_empty -- see task_pq.h for the header comment */
bool task_pq_is_empty(task_pq_t *tpq) {
  assert(tpq != NULL);
  // TODO: complete this function and replace the
  // return value with a suitable value
  return false;
}

/* task_pq_add -- see task_pq.h for the header comment */
bool task_pq_add(task_pq_t *tpq, task_t *task) {
  assert(tpq != NULL);
  assert(task != NULL);

  // TODO: complete this function

  // this function always returns true
  return true;
}

/* heap_remove_most_urgent_task */
task_t *task_pq_remove_most_urgent_task(task_pq_t *tpq) {
  assert(tpq != NULL);
  // TODO: complete this function and replace the
  // return value with a suitable value
  return NULL;
}
