/*
 * CMSC 14300
 * Autumn 2025
 * Homework #6: simple code for running the task priority queue
 *
 * You may modify this file.
 */

#include <assert.h>
#include <stdbool.h>
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


#include "task.h"
#include "task_pq.h"
#include "util.h"

void parse_arguments(int argc, char *argv[],
                     bool *check_basic,
                     char **filename,
		     bool *check_mixed) {                     
  int opt;
  char *usage = "Usage: %s [-b] [-f filename] [-m] [-h]";
  *filename = NULL;
  *check_basic = false;
  *check_mixed = false;
  
  // Parse the arguments
  while ((opt = getopt(argc, argv, "bf:mh")) != -1) {
    switch (opt) {
      case 'f':
        *filename = strdup(optarg);
        break;
      case 'b':
        *check_basic = true;
        break;
      case 'h':
        printf(usage, argv[0]);
        printf("\n");
        exit(0);
      case 'm':
        *check_mixed = true;
        break;
      default:
        fprintf(stderr, usage, argv[0]);
        exit(1);
    }
  }
}

void test_basic() {
  task_pq_t *tpq = task_pq_create();
  assert(task_pq_is_empty(tpq));
  task_pq_free(tpq, true);
}

void test_add_remove(char *filename) {
  unsigned int num_tasks;
  task_t **tasks = read_tasks_from_file(filename, &num_tasks);
  if (tasks == NULL) {
    // read function will generate an error message.
    exit(1);
  }

  task_pq_t *tpq = task_pq_create();

  printf("adding tasks...\n");
  for (int i = 0; i < num_tasks; i++) {
    print_task(tasks[i]);
    task_pq_add(tpq, tasks[i]);
  }
  printf("\n\n");

  assert(!task_pq_is_empty(tpq));

  printf("printing priority queue array...\n");
  task_pq_print(tpq);
  printf("\n\n");
    
  printf("removing tasks in order of urgency...\n");
  for (int i = 0; i < num_tasks; i++) {
    task_t *task = task_pq_remove_most_urgent_task(tpq);
    print_task(task);
    free_task(task);
  }
  printf("\n\n");
  
  assert(task_pq_is_empty(tpq));

  task_pq_free(tpq, true);
  // free the array that held the tasks.
  free(tasks);
}

void test_mixed_add_remove() {
  unsigned int num_tasks;
  task_t **tasks = read_tasks_from_file("sample_tasks/ten_tasks.txt", &num_tasks);
  if (tasks == NULL) {
    // read function will generate an error message.
    exit(1);
  }

  task_pq_t *tpq = task_pq_create();

  unsigned int i;
  unsigned int j;
  unsigned int expected_tids[] = {10, 11, 14, 2, 15, 12, 3, 18, 1, 13};

  
  // add the first five tasks
  for (i = 0; i < 5; i++) {
    task_pq_add(tpq, tasks[i]);    
  }
  // remove 3
  for (j = 0; j < 3; j++) {
    task_t *task = task_pq_remove_most_urgent_task(tpq);
    assert(get_tid_task(task) == expected_tids[j]);
    free_task(task);
  }

  // add the next three tasks
  for (;i < 8; i++) {
    task_pq_add(tpq, tasks[i]);    
  }

  // remove 3
  for (; j < 6; j++) {
    task_t *task = task_pq_remove_most_urgent_task(tpq);
    assert(get_tid_task(task) == expected_tids[j]);
    free_task(task);
  }

  
  // add last two tasks
  for (; i < 10; i++) {
    task_pq_add(tpq, tasks[i]);    
  }
  
  // remove the last four
  for (; j < 10; j++) {
    task_t *task = task_pq_remove_most_urgent_task(tpq);
    assert(get_tid_task(task) == expected_tids[j]);
    free_task(task);
  }

  free(tasks);
  // no tasks left.
  task_pq_free(tpq, false);
}


int main(int argc, char *argv[]) {
  bool check_basic, check_mixed;
  char *filename = NULL;

  parse_arguments(argc, argv, &check_basic, &filename, &check_mixed);
  if (check_basic) {
    printf("\ntrying create, free, and is_empty\n");
    test_basic();
  }

  if (filename != NULL) {
    test_add_remove(filename);
    free(filename);
  }
  
  if (check_mixed) {
    test_mixed_add_remove();
  }
}
