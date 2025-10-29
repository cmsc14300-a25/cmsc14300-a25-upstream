/*
 * CMSC 14300
 * Autumn 2025
 * Homework #5: scheduler header file
 *
 * Do NOT modify this file.
 */

#include "task_manager.h"

/* run_tasks: Runs cycles until all the tasks are done.                                             
 *                                                                                                                  
 * tm: a task manager                                                                                               
 * time_slice: array with time slices for each                                                         
 * max_cycles: the maximum number of cycles to run
 * time_used: an out parameter for the amount of time used to run the tasks.
 *
 * Returns: the number of cycles run.
 */
int run_tasks(task_manager_t *tm, int time_slice,
              unsigned int max_cycles,
              unsigned int *time_used);
