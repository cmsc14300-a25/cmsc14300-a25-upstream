/*** DO NOT CHANGE THIS FILE ***/

#include "util.h"

#include <stdio.h>
#include <stdlib.h>

#include "task.h"

#define MAX_LINE_LEN 1000

task_t **read_tasks_from_file(char *filename, unsigned int *result_len) {
  FILE *fp;
  unsigned int num_tasks;
  size_t line_len = MAX_LINE_LEN;
  char *line = (char *)malloc(sizeof(char) * line_len);
  if (line == NULL) {
    fprintf(stderr, "read_tasks: allocated failed (error loading '%s')\n",
            filename);
    *result_len = 0;
    return NULL;
  }

  // open task file for reading
  fp = fopen(filename, "r");
  if (!fp) {
    fprintf(stderr, "read_tasks: Unable to open file '%s'\n", filename);
    return NULL;
  }

  // read image size information
  if (fscanf(fp, "%u\n", &num_tasks) != 1) {
    fprintf(stderr,
            "read_task: Invalid number of  tasks size (error loading '%s')\n",
            filename);
    // cleanup...
    fclose(fp);
    return NULL;
  }

  // memory allocation for task data
  task_t **tasks = (task_t **)malloc(sizeof(task_t *) * num_tasks);
  if (tasks == NULL) {
    fprintf(stderr,
            "read_tasks: cannot proceed because malloc returned NULL\n");
    // cleanup...
    free(line);
    fclose(fp);
    return NULL;
  }

  // read tasks
  for (int i = 0; i < num_tasks; i++) {
    int nc = getline(&line, &line_len, fp);
    if (nc == 0) {
      fprintf(stderr, "read_tasks: bad format\n");
      // cleanup...
      free(line);
      fclose(fp);
      for (int j = 0; j < i; j++) {
        free_task(tasks[i]);
      }
      free(tasks);
      return NULL;
    }
    tasks[i] = mk_task_from_line(line);
  }

  // cleanup
  free(line);
  fclose(fp);

  *result_len = num_tasks;
  return tasks;
}
