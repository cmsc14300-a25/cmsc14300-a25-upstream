/*
 * CMSC 14300
 * Autumn 2025
 * Homework #5: simple code for running the task scheduler
 *
 * You will modify this file.
 */

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "scheduler.h"
#include "task_manager.h"
#include "util.h"

// Defined w/ getopt library.  Include here to make VS Code happy.
extern char* optarg;

/* parse_arguments: parse the command-line arguments */
bool parse_arguments(int argc, char* argv[], char** filename, 
                     unsigned int* time_slice, unsigned int* max_cycles) {
  int opt;
  char* usage =
      ("Usage: %s [-c max cycles] [-f filename] [-t time_slice][-h]");

  // set the defaults
  *time_slice = 10;
  *max_cycles = 1;
  // duplicate to make the process of freeing the name
  // easier later.
  *filename = NULL;

  // Parse the arguments
  while ((opt = getopt(argc, argv, "c:f:t:h")) != -1) {
    switch (opt) {
      case 'c':
        *max_cycles = atoi(optarg);
        break;
      case 'h':
        printf(usage, argv[0]);
        printf("\n");
        return false;
      case 'f':
        *filename = strdup(optarg);
        break;
      case 't':
        *time_slice = atoi(optarg);
        break;
      default:
        fprintf(stderr, usage, argv[0]);
        return false;
    }
  }
  if (*filename == NULL) {
    *filename = strdup("sample_tasks/one_task.txt");
  }
  return true;
}

int main(int argc, char* argv[]) {
  unsigned int num_tasks;
  unsigned int time_slice;
  unsigned int max_cycles;
  char* filename = NULL;

  bool parse_successful = parse_arguments(argc, argv, &filename,
                                          &time_slice, &max_cycles);
  if (!parse_successful) {
    if (filename != NULL) { free(filename); }
    return 1;
  }

  task_t** tasks = read_tasks_from_file(filename, &num_tasks);
  if (tasks == NULL) {
    if (filename != NULL) { free(filename); }
    return 1; 
  }
  task_manager_t* tm = tm_create();

  for (int i = 0; i < num_tasks; i++) {
    tm_add_task(tm, tasks[i]);
  }

  printf("Tasks to run:\n");
  tm_print(tm);
  printf("\n");

  unsigned int time_used;
  unsigned int num_cycles = run_tasks(tm, time_slice, max_cycles, &time_used);
 
  printf("Results: time used: %u\tcycles run: %u\n", time_used, num_cycles);
  printf("Tasks after run\n");
  tm_print(tm);

  tm_free(tm);
  // The previous function call will free the tasks, but not the task array
  free(tasks);
  free(filename);
}
