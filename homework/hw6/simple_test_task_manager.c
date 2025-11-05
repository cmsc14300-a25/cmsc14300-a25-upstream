/*
 * CMSC 14300
 * Autumn 2025
 * Homework #5: Simple test code for task managers.
 *
 * You may modify this file.
 */

#include <assert.h> 
#include <getopt.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "task_manager.h"

void parse_arguments(int argc, char* argv[], bool* check_basic, bool* check_add,
                     bool* check_run, bool* check_drop) {
  int opt;
  char* usage = "Usage: %s [-b] [-a] [-r] [-d] [-h]";

  *check_add = false;
  *check_basic = false;
  *check_run = false;
  *check_drop = false;

  // Parse the arguments
  while ((opt = getopt(argc, argv, "bardh")) != -1) {
    switch (opt) {
      case 'a':
        *check_add = true;
        break;
      case 'b':
        *check_basic = true;
        break;
      case 'd':
        *check_drop = true;
        break;
      case 'h':
        printf(usage, argv[0]);
        printf("\n");
        exit(0);
      case 'r':
        *check_run = true;
        break;
      default:
        fprintf(stderr, usage, argv[0]);
        exit(1);
    }
  }
}

/* create and free a task manager */
void test_basic(void) {
  task_manager_t* tm = tm_create();
  tm_free(tm);
}

/* create a task manager from a given set of tasks */
task_manager_t* make_sample(task_t* tasks[], int num_tasks,
                            unsigned int* num_active) {
  task_manager_t* tm = tm_create();
  *num_active = 0;

  for (int i = 0; i < num_tasks; i++) {
    tm_add_task(tm, tasks[i]);
    if (is_active_task(tasks[i]) > 0) {
      *num_active = *num_active + 1;
    }
  }
  return tm;
}

/* code for testing the run cycle function. */
void check_run_cycle(bool check_drop) {
  unsigned int expected_num_active;
  // Need to remake the tasks, since they get freed in
  // test_add_task_and_others);
  task_t* tasks1[] = {mk_task(0, 0, 0), mk_task(5, 10, 15), mk_task(10, 10, 20),
                      mk_task(2, 3, 3)};
  unsigned int num_tasks = sizeof(tasks1) / sizeof(task_t*);
  task_manager_t* tm = make_sample(tasks1, num_tasks, &expected_num_active);

  unsigned int time_used = tm_run_cycle(tm, 10);
  assert(time_used == 23);

  if (check_drop) {
    printf("trying to drop tasks\n");
    unsigned int num_active_before_drop;
    unsigned int num_active_after_drop;
    unsigned int num_finished;
    tm_count_task_status(tm, &num_active_before_drop, &num_finished);
    assert(tm_drop_finished(tm) == num_finished);
    tm_count_task_status(tm, &num_active_after_drop, &num_finished);
    assert(num_finished == 0);
    assert(num_active_before_drop == num_active_after_drop);
  }

  tm_free(tm);
}

/* code for testing the run cycle function on an empty task manager */
void check_run_cycle_empty(bool check_drop) {
  task_manager_t* tm = tm_create();

  unsigned int time_used = tm_run_cycle(tm, 10);
  assert(time_used == 0);
  unsigned int num_active;
  unsigned int num_finished;
  tm_count_task_status(tm, &num_active, &num_finished);


  assert(num_active == 0);
  assert(num_finished == 0);  

  if (check_drop) {
    printf("trying to drop tasks\n");
    assert(tm_drop_finished(tm) == 0);
  }
  tm_free(tm);
}

/* Build a task manager, check the status counts, and then free it */
void test_add_task_and_others(void) {
  task_t* tasks[] = {mk_task(0, 0, 0), mk_task(5, 10, 15), mk_task(10, 10, 20),
                     mk_task(2, 3, 3)};
  int num_tasks = sizeof(tasks) / sizeof(task_t*);
  unsigned int expected_num_active;
    task_manager_t* tm = make_sample(tasks, num_tasks, &expected_num_active);
  unsigned int expected_num_finished = num_tasks - expected_num_active;

  unsigned int num_active;
  unsigned int num_finished;
  tm_count_task_status(tm, &num_active, &num_finished);
  assert(expected_num_active == num_active);
  assert(expected_num_finished == num_finished);

  tm_free(tm);
}

int main(int argc, char* argv[]) {
  bool check_basic;
  bool check_add;
  bool check_run;
  bool check_drop;

  parse_arguments(argc, argv, &check_basic, &check_add, &check_run,
                  &check_drop);
  if (check_basic) {
    printf("trying create and free\n");
    test_basic();
  }

  if (check_add) {
    printf("trying add task + getters\n");
    test_add_task_and_others();
  }

  // Check the run cycle function
  if (check_run || check_drop) {
    printf("trying run cycle with tasks\n");
    check_run_cycle(check_drop);
    printf("trying run cycle without tasks\n");
    check_run_cycle_empty(check_drop);
  }
}
