#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include <time.h>

// the maximum number of threads
#define MAX_NUM_THREADS 32

// the width of the sample matrix
#define GRID_WIDTH 50


typedef struct {
    int row0;
    int col0;
    int wid;
    int ht;
} rect_t;

typedef struct worker {
  rect_t rect;
  int **matrix;
  int result;
} worker_t;

void *worker(void *data) {
  worker_t *args = data;
  rect_t rect = args->rect;
  int **matrix = args->matrix;

  int tot = 0;
  for (int r = 0;  r < rect.ht;  ++r) {
    for (int c = 0;  c < rect.wid;  ++c) {
      tot += matrix[r][c];
    }
  }

  args->result = tot;

  return 0;
}


int compute_sum(int num_threads, int **matrix) {
  if (num_threads == 1) {
    // sequential version
    worker_t worker_args = {
      .rect = {.row0 = 0, .col0 = 0, .ht = GRID_WIDTH, .wid = GRID_WIDTH},
      .matrix = matrix
    };
    worker (&worker_args);
    return worker_args.result;
  } else {
    // parallel version; we compute in horizontal strips
    int strip_ht = GRID_WIDTH / num_threads;

    pthread_t *tids = malloc(sizeof(pthread_t) * num_threads);
    // check tids
    
    worker_t *worker_args = malloc(sizeof(*worker_args) * num_threads);
    // check worker_args
    
    // fire off the threads
    int ht;
    for (int i = 0;  i < num_threads;  ++i) {
      int row0 = row0 = i * strip_ht;
      if (i < num_threads - 1) {
        ht = strip_ht;
      } else {
        ht = GRID_WIDTH - (i * strip_ht);
      }
      worker_args[i] = (worker_t) {
            .rect = {.row0 = row0, .col0 = 0, .ht = ht, .wid = GRID_WIDTH},
            .matrix = matrix};
      pthread_create (&tids[i], 0, worker, &worker_args[i]);
    }

    // wait for the threads
    int total_over_threads = 0;
    for (int i = 0;  i < num_threads;  ++i) {
      pthread_join (tids[i], 0);
      total_over_threads += worker_args[i].result;
    }

    free(tids);
    free(worker_args);
    return total_over_threads;
  }
}



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

    int **matrix = (int **)malloc(sizeof(*matrix) * GRID_WIDTH);
    // check matrix
    for (unsigned int i = 0; i < GRID_WIDTH; i++) {
      matrix[i] = (int *)malloc(sizeof(*matrix[i]) * GRID_WIDTH);
      for (unsigned int j = 0; j < GRID_WIDTH; j++) {
        matrix[i][j] = j;
      }
    }

    int tot = compute_sum(num_threads, matrix);
    printf("Result is: %d\n", tot);

    return 0;
}
