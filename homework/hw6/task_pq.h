/*
 * CMSC 14300
 * Autumn 2025
 * Homework #6: Task priority queue header file
 * 
 * You may NOT modify this file.
 */

#ifndef TASK_PQ_H
#define TASK_PQ_H

#include <stdbool.h>
#include "task.h"

typedef struct task_pq task_pq_t;

/* task_pq_create: construct a new priority queue
 *
 * Returns: pointer to a task priority queue
 */
task_pq_t *task_pq_create();

/* task_pq_free: free the infrastructure for the priority
 *   queue.  Free the tasks in the priority queue only
 *   if should_free_tasks is true.
 * 
 * Returns: nothing
 */
void task_pq_free(task_pq_t *tpq, bool should_free_tasks);

/* task_pq_print: optional function that prints the
 *   contents of the priority queue.
 *
 * tpq: the priority queue of interest
 * 
 * Returns: nothing
 */
void task_pq_print(task_pq_t *tpq);

/* task_pq_is_empty: determines whether the priority
 *   is empty
 * 
 * tpq: the priority queue of interest
 * 
 * Returns: true, if the priority queue is empty, and
 *   false otherwise.
*/
bool task_pq_is_empty(task_pq_t *tpq);

/* task_pq_add_task: add a task to the priority queue
 * 
 * tpq: the priority queue of interest
 * task: the task to add
 * 
 * Returns: nothing
 */
bool task_pq_add(task_pq_t *tpq, task_t *task);

/* heap_remove_most_urgent_task: removes the most urgent
 *   task from the priority queue.  Returns NULL if the
 *   priority queue is empty.
 * 
 * tpq: the priority queue of interest
 * 
 * Returns: the most urgent task or NULL, if the priority
 *   queue is empty.
*/
task_t *task_pq_remove_most_urgent_task(task_pq_t *tpq);

#endif