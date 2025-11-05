/* Copy your implementation of task.c from hw5 and
 * then add these functions to the bottom task.c  Do
 * NOT modify these functions.
 *
 * FYI, this code will not compile on its own.  It
 * must be incorprated into task.c
 */

 
/* run_task_slice_with_print -- see task.h for header comment */
bool run_task_slice_with_print(task_t *task, unsigned int time_slice,
                               unsigned int *time_used) {

  /***** Do not remove or modify the print statements in this function *****/

  printf("RTS: Running tid: %u", task->tid);
  printf("  original -- priority: %u  running time: %u",
        task->priority, task->running_time);
  bool rv = run_task_slice(task, time_slice, time_used);
  if (rv) {
    printf("  Task completed\n");    
  } else {
    // Update the priority with a goal of scrambling the order the
    // tasks should be done in the next cycle.
    task->priority = (3 * task->priority + 27) % 7;    
    printf("  new -- priority: %u. running time: %u\n", 
           task->priority, task->running_time);   
  }
  return rv;
}

/* is_more_urgent_task -- see task.h for header comment */
bool is_more_urgent_task(task_t *task1, task_t *task2) {
  assert(task1->tid != task2->tid);
  return ((task1->priority < task2->priority) ||
          ((task1->priority == task2->priority) && (task1->tid < task2->tid)));
}
