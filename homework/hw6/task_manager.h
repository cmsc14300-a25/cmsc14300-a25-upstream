/*
 * CMSC 14300
 * Autumn 2025
 * Homework #6: Task manager header file
 *
 * You may NOT modify this file.
 */

#ifndef TASK_MANAGER_H
#define TASK_MANAGER_H

#include <stdbool.h>

#include "task.h"

typedef struct task_manager task_manager_t;

/* tm_create: create an empty task manager
 *
 * Returns: a pointer to a task manager
 */
task_manager_t *tm_create();

/* tm_free: free all the space associated with a task manager along with
 *   any tasks that are still in the heap.
 *
 * tm: a pointer to a task manager
 *
 */
void tm_free(task_manager_t *tm);

/* tm_print: (optional) print the tasks in the manager
 *
 * tm: a pointer to a task manager
 *
 */
void tm_print(task_manager_t *tm);

/* tm_count_status: count the number of active and finished tasks
 *
 * tm: a task manager
 * num_active: an OUT parameter for returning the number of active tasks
 * num_finished: an OUT parameter for returning the number of finished tasks
 *
 * Returns: nothing
 */
void tm_count_task_status(task_manager_t *tm, 
                          unsigned int *num_active,
                          unsigned int *num_finished);

/* tm_add_task: add a new task to the task manager
 *
 * tm: a pointer to a task manager
 * task: a pointer to a task
 *
 * Returns: nothing
 */
void tm_add_task(task_manager_t *tm, task_t *task);

/* tm_run_cycle: "runs" each active task for no more than the specified
 *   time slice.
 *
 * tm: a task manager
 * time_slice: the maximum amount of time to run a task
 *
 * Returns: the total time used by the tasks.
 */
unsigned int tm_run_cycle(task_manager_t *tm, unsigned int time_slice);

/* tm_drop_finished: drop the finished tasks from the task manager
 *
 * tm: a task manager
 *
 * Returns: the number of dropped tasks.
 */
unsigned int tm_drop_finished(task_manager_t *tm);

#endif
