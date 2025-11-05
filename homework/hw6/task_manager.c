/*
 * CMSC 14300
 * Autumn 2025
 * Homework #6: Task manager implementation
 * 
 * You will modify this file.
 */

#include "task_manager.h"

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "growable_array.h"
#include "task.h"
#include "task_pq.h"

/********* Do NOT modify this structure definition *********/
/* Structure definition for the task manager */
struct task_manager {
  unsigned int num_active;
  unsigned int num_finished;
  task_pq_t* tasks;
};

/***** Helper functions *****/

// Put your helper functions here.

/***** API functions *****/

/* tm_create -- see task_manager.h for the header comment */
task_manager_t *tm_create(void) {
  // TODO: complete this function and replace
  // the return value with an appropriate value.
  return NULL;
}

/* tm_free -- see task_manager.h for the header comment */
void tm_free(task_manager_t *tm) {
  // TODO: complete this function
}

/* tm_print -- see task_manager.h for the header comment */
void tm_print(task_manager_t *tm) {
  // OPTIONAL: complete this function 
}

/* tm_add_task -- see task_manager.h for the header comment */
void tm_add_task(task_manager_t *tm, task_t *task) {
  assert(tm != NULL);
  assert(task != NULL);  
  // TODO: complete this function    
}

/* tm_count_status -- see task_manager.h for the header comment */
void tm_count_task_status(task_manager_t *tm,
                          unsigned int *num_active,
                          unsigned int *num_finished) {
  // TODO: complete this function    
}

/* tm_run_cycle -- see task_manager.h for the header comment */
unsigned int tm_run_cycle(task_manager_t *tm, unsigned int time_slice) {
  assert(tm != NULL);
  // TODO: complete this function and replace the return
  // value with a suitable value.   
  return 0;
}

/* tm_drop_finished -- see task_manager.h for the header comment */
unsigned int tm_drop_finished(task_manager_t *tm) {
  assert(tm != NULL);
  // TODO: complete this function and replace the return
  // value with a suitable value.    
  return 0;
}



