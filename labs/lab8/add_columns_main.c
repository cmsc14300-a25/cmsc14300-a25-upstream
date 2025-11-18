/*
 * CMSC 14300
 * Autumn 2025
 * Homework #6: Growable array implementation
 *
 * You may NOT modify this file.
 */

#include <assert.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// the maximum number of threads
#define MAX_NUM_THREADS 32

// prototype of the function from add_columns
int *compute_sum_columns(int num_threads, int **matrix, int num_rows, int num_cols);

int main (int argc, const char **argv) {
  if (argc != 2) {
    fprintf(stderr, "usage: mb <num-threads>\n");
    exit (1);
  }

  // parse the command-line argument
  char *endp;
  int num_threads = strtol(argv[1], &endp, 10);
  if ((*endp != '\0') || (num_threads <= 0) || (num_threads > MAX_NUM_THREADS)) {
    fprintf(stderr, "invalid number of threads\n");
    exit (1);
  }

  int grid_width = 50;
  int **matrix = (int **)malloc(sizeof(*matrix) * grid_width);
  // check matrix
  for (unsigned int i = 0; i < grid_width; i++) {
    matrix[i] = (int *)malloc(sizeof(*matrix[i]) * grid_width);
    for (unsigned int j = 0; j < grid_width; j++) {
      matrix[i][j] = j;
    }
  }

  int* tot = compute_sum_columns(num_threads, matrix, grid_width, grid_width);
  for (int j = 0; j < grid_width; j++) {
    assert(tot[j] == matrix[0][j] * grid_width);
  }

  printf("Success!\n");

  return 0;
}
