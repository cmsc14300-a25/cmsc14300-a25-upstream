#include <assert.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include <time.h>

// the maximum number of threads

typedef struct {
    int row0;
    int col0;
    int wid;
    int ht;
} rect_t;

/******* WRITE THIS BLOCK *******/


// definition for the structure used to pass arguments to the worker
// and for the worker to send results back to the thread.
typedef struct worker {
  rect_t rect;
  int **matrix;

  // TODO: add a field for the return value 

} worker_t;

void *worker(void *data) {
  worker_t *args = data;

  // TODO: add code to compute sum of each column in the stripe

  // always return NULL;
  return NULL;
}

/******* END WRITE THIS BLOCK *******/


/* compute_sum_columns: compute the sum of the values in each column
 *   using the specified number of threads
 */
int *compute_sum_columns(int num_threads, int **matrix, int num_rows, int num_cols) {
  if (num_threads == 1) {
    // sequential version

    // TODO: Add code to set up the argument and call the worker
    // function directly for the one sequential (one thread) version.
    // Replace the NULL with a suitable return value

    return NULL;
   

  } else {
    // parallel version; we compute in horizontal strips
    int strip_ht = num_rows / num_threads;

    pthread_t *tids = malloc(sizeof(pthread_t) * num_threads);
    if (tids == NULL) {
      fprintf(stderr, "compute_col_sums: out of space\n");
      exit(1);
    }

    worker_t *worker_args = malloc(sizeof(*worker_args) * num_threads);
    if (worker_args == NULL) {
      fprintf(stderr, "compute_col_sums: out of space\n");
      free(tids);
      exit(1);
    }

    // TODO: Add code to set up each thread and create it


    // space for the result
    int *total_over_threads = (int *) calloc(sizeof(int), num_cols);
    
    // TODO: Add code to wait for the threads and to
    // combine the partial results into the final result

    free(tids);
    free(worker_args);
    return total_over_threads;
  }
}



