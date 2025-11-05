/*
 * CMSC 14300
 * Autumn 2025
 * Homework #6: Simple program to verify that the
 *   functions from task_extra_functions have been
 *   successfully added to the student's implementation
 *   of task.c.
 */

#include <assert.h>
#include "task.h"

int main(int argc, char *argv[]) {
    task_t *task1 = mk_task(10, 20, 30);
    task_t *task2 = mk_task(11, 20, 30);
    unsigned int time_used;
    run_task_slice_with_print(task1, 10, &time_used);

    assert(is_more_urgent_task(task1, task2));
}