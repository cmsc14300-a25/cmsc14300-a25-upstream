#ifndef UTIL_H
#define UTIL_H

#include "task.h"

/* read_tasks_from_file: read a collection of tasks from
 *   a file. The first line in the file contains the
 *   number of tasks. Each subsequent line contains information
 *   for one task: task identifier, priority, running time. 
 * 
 * filename: the name of the task file
 * result_len: an out parameter for communicating the length
 *   of the result
 * 
 * Returns: an array of pointers to tasks or NULL, if the file
 *   does not exist or the format is bad. 
 */
task_t **read_tasks_from_file(char *filename, unsigned int *result_len);

#endif
