/*
 * CMSC 14300
 * Autumn 2025
 * Homework #6: Task module header file 
 * 
 * This header file introduces two functions--run_task_slice_with_print
 * and is_more_urgent_task-- that were not part of the Homework #5 task API.
 * 
 * You may NOT modify this file.
 */

#ifndef TASK_H
#define TASK_H

#include <stdbool.h>
#include <stdlib.h>

// The task_t type is opaque.  Clients can use it, but they cannot
// access the fields of the underlying structure.
typedef struct task task_t;

/* mk_task: make a task structure from the specified information.
 *
 * tid: a unique identifier for the task
 * priority: the priority of the task
 * running_time: the running time of the task
 *
 * Returns: a pointer to a task
 */
task_t *mk_task(unsigned int tid, unsigned int priority,
			  unsigned int running_time);


/* free_task: free the space associated with a task
 *
 * task: the task of interest
 *
 * Returns: Nothing
 */
void free_task(task_t *task);


/* get_tid_task: get the task identifier for the task
 *
 * task: the task of interest
 *
 * Returns: the task identifier for the task
 */
unsigned int get_tid_task(task_t *task);


/* get_priority_task: get the priority for the task
 *
 * task: the task of interest
 *
 * Returns: the task's priority
 */
unsigned int get_priority_task(task_t *task);


/* is_active_task: determines whether a task has a running time
 *   greater than zero.
 *
 * task: the task of interest
 * 
 * Returns: true, if the task is active and false, if it is finished.
 */
bool is_active_task(task_t *task);


/* print_task: print the task information in a human-friendly form.
 *
 * task: the task of interest
 *
 * Returns: nothing
 */
void print_task(task_t *task);


/* mk_task_from_line: parse the line and create a task
 *   information structure.
 *
 * line: a comma-separated string with the task information
 *
 * Returns: a task information structure or NULL, if
 *   line does not have the correct format.
 */
task_t *mk_task_from_line(char *line);


/* run_task_slice: "runs" a task for no more than the specified time slice.
 *   Modifies the running time of the task to reflect the amount
 *   of time the task has run.
 *
 * task: the task of interest
 * time_slice: the maximum amount of time to run the task
 * time_used: an out parameter for sharing the amount of time actually used
 *   by the task
 *
 * Returns: true, if the task is finished and false, otherwise.
 */
bool run_task_slice(task_t *task, unsigned int time_slice,
		    unsigned int *time_used);


/* run_task_slice_with_print: "runs" a task for no more than the specified
 *   time slice. Modifies the running time of the task to reflect the amount
 *   of time the task has run. Prints information about
 *   the task before and after it is run and updates the task priority.
 *
 * task: the task of interest
 * time_slice: the maximum amount of time to run the task
 * time_used: an out parameter for sharing the amount of time actually used
 *   by the task
 *
 * Returns: true, if the task is finished and false, otherwise.
 */
bool run_task_slice_with_print(task_t *task, unsigned int time_slice,
                               unsigned int *time_used);

/* is_more_urgent_task: determines which task comes first in the
 *   task ordering. The tasks must have different task ids.
 * 
 * task1: first operand
 * task2: second operand
 *
 * Returns: true if task 1 comes before task2, false otherwise.
 */
bool is_more_urgent_task(task_t *task1, task_t *task2);
 

#endif
