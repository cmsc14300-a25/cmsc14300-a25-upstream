/*
 * CMSC 14300
 * Autumn 2025
 * Homework #5: Simple test code for tasks.
 *
 * You may modify this file.
 */

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "task.h"

// Defined w/ getopt library.  Include here
// to make VS Code happy.
extern char *optarg;

/* parse_arguments: parse the command-line arguments */
bool parse_arguments(int argc, char *argv[], unsigned int *tid,
                     unsigned int *priority, unsigned int *running_time,
                     unsigned int *time_slice, bool *check_str) {
  int opt;
  char *usage = ("Usage: %s [-p prioriy] [-i tid] "
                 "[-r_time_time] [-t time_slice] [-s] [-h]");

  *tid = 0;
  *priority = 0;
  *running_time = 0;
  *time_slice = 0;
  *check_str = false;

  // Parse the arguments
  while ((opt = getopt(argc, argv, "i:p:r:t:sh")) != -1) {
    switch (opt) { 
      case 'h':
        printf(usage, argv[0]);
        printf("\n");
        exit(0);
      case 'i':
        *tid = atoi(optarg);
        break;              
      case 'p':
        *priority = atoi(optarg);
        break;
      case 'r':
        *running_time = atoi(optarg);
        break;
      case 's':
        *check_str = true;
        break;         
      case 't':
        *time_slice = atoi(optarg);
        break;
      default:
        fprintf(stderr, usage, argv[0]);
        return false;
    }
  }
  return true;
}

/* check_task: do a set of basic checks on a task */
task_t *check_task(task_t *t, unsigned int tid, unsigned int priority,
                   unsigned int running_time) {
  assert(get_tid_task(t) == tid);
  assert(get_priority_task(t) == priority);  
  assert(((running_time > 0) && is_active_task(t)) ||
         ((running_time == 0) && (!is_active_task(t))));
  return t;
}

int main(int argc, char *argv[]) {
  unsigned int tid;
  unsigned int priority;
  unsigned int running_time;
  unsigned int time_slice;
  bool check_str;

  bool parse_successful =
      parse_arguments(argc, argv, &tid, &priority, &running_time,
                      &time_slice, &check_str);
  if (!parse_successful) {
    return 1;
  }

  task_t *t;
  if (check_str) {
    char tmp[200];
    snprintf(tmp, 200, "%u,%u,%u", tid, priority, running_time);
    printf("Checking string constructor: %s\n", tmp);
    t = mk_task_from_line(tmp);
  } else {
    printf("Checking regular constructor\n");
    t = mk_task(tid, priority, running_time);
  }

  check_task(t, tid, priority, running_time);
  print_task(t);

  if (time_slice > 0) {
    unsigned int time_used;
    bool is_finished;

    is_finished = run_task_slice(t, time_slice, &time_used);
    printf("is_finished: %s\ttime_used: %u\n", 
           is_finished ? "yes" : "no",
           time_used);
  }

  free_task(t);
  return 0;
}
