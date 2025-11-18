/* pthread-mb.c
 *
 * To compile:  clang -std=c11 -O3 -o mb pthread-mb.c
 *
 * Usage:       mb <nthreads>
 */

#include <math.h>
#include <pthread.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// the maximum number of threads
#define MAX_NUM_THREADS 32

// the width of the result grid
#define GRID_WIDTH 2048

// maximum number of iterations for a pixel
#define MAX_COUNT 2024

// location and size of rectangle covered by the grid
#define X_BASE -1.5
#define Y_BASE 0.4
#define WIDTH 0.8

void computePixel(uint8_t *img, int row, int col) {
  double pixel_wid = WIDTH / (double)GRID_WIDTH;

  // initial complex value for pixel location
  double px_re = X_BASE + (double)col * pixel_wid;
  double px_im = Y_BASE - (double)row * pixel_wid;

  // iterate until either we know that the point is not in the set
  // or we reach the maximum count
  int cnt = 0;
  double re = px_re;
  double im = px_im;
  while (cnt < MAX_COUNT) {
    double re2 = re * re;
    double im2 = im * im;
    if ((re2 + im2) > 4.0) {
      break;
    }
    cnt++;
    im = px_im + 2.0 * re * im;
    re = px_re + re2 - im2;
  }

  // the start index of the pixel in img
  int pxIdx = (row * GRID_WIDTH * 3) + (col * 3);

  if (cnt < MAX_COUNT) {
    // generate a color for the pixel from the count
    float t = 11.0f * powf((float)cnt, 0.2);
    img[pxIdx] = (int)(255.0 * ((sinf(t) + 1.7) / 2.7));
    img[pxIdx + 1] =
        (int)(255.0 * ((sinf(t + 2.0 * M_PI / 3.0) + 1.7) / 2.7));
    img[pxIdx + 2] =
        (int)(255.0 * ((sinf(t - 2.0 * M_PI / 3.0) + 1.7) / 2.7));
  } else {
    img[pxIdx] = 0;
    img[pxIdx + 1] = 0;
    img[pxIdx + 2] = 0;
  }
}

typedef struct {
  int row0;
  int col0;
  int wid;
  int ht;
} rect_t;

typedef struct worker {
  rect_t rect;
  uint8_t *img;
} worker_t;

void * worker(void * data) {
  worker_t* args = data;
  rect_t rect = args->rect;

  for (int r = 0; r < rect.ht; ++r) {
    for (int c = 0; c < rect.wid; ++c) {
      computePixel(args->img, rect.row0 + r, rect.col0 + c);
    }
  }

  return NULL;
}

// output the image
void output_image(uint8_t *result) {
  FILE* outF = fopen("out.ppm", "wb");
  fprintf(outF, "P6\n%d %d 255\n", GRID_WIDTH, GRID_WIDTH);
  fwrite(result, (GRID_WIDTH * GRID_WIDTH * 3), 1, outF);
  fclose(outF);
}

uint8_t *computeMB(int num_threads) {
  uint8_t *result =
      (uint8_t*)malloc(sizeof(uint8_t) * (GRID_WIDTH * GRID_WIDTH * 3));    
  if (num_threads == 1) {
    // sequential version
    worker_t worker_args = {
        .rect = {.row0 = 0, .col0 = 0, .ht = GRID_WIDTH, .wid = GRID_WIDTH},
        .img = result};
    worker(&worker_args);
  } else {
    // parallel version; we compute in horizontal strips
    int strip_ht = GRID_WIDTH / num_threads;

    pthread_t *tids = malloc(sizeof(pthread_t) * num_threads);
    // check tids...

    worker_t* worker_args = malloc(sizeof(*worker_args) * num_threads);
    // check worker_args ...

    // fire off the threads
    int ht;
    for (int i = 0; i < num_threads; ++i) {
      int row0 = row0 = i * strip_ht;
      if (i < num_threads) {
        ht = strip_ht;
      } else {
        // do whatever is left at this point.
        ht = GRID_WIDTH - i * strip_ht;
      }
      worker_args[i] = (worker_t){
          .rect = {.row0 = row0, .col0 = 0, .ht = ht, .wid = GRID_WIDTH},
          .img = result};
      pthread_create(&tids[i], 0, worker, &worker_args[i]);
    }

    // wait for the threads
    for (int i = 0; i < num_threads; ++i) {
      pthread_join(tids[i], 0);
    }

    free(tids);
    free(worker_args);
  }
  return result;
}

int main(int argc, const char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "usage: mb <num-threads>\n");
    exit(1);
  }

  // parse the command-line argument
  char* endp;
  int num_threads = strtol(argv[1], &endp, 10);
  if ((*endp != '\0') || (num_threads <= 0) ||
      (num_threads > MAX_NUM_THREADS)) {
    fprintf(stderr, "invalid number of threads\n");
    exit(1);
  }

  // set up the timing infrastructure
  struct timespec tim0, tim1;
  clock_gettime(CLOCK_REALTIME, &tim0);

  uint8_t *result = computeMB(num_threads);

  // get the running time
  clock_gettime(CLOCK_REALTIME, &tim1);

  output_image(result);
  free(result);

  // report running time
  int64_t nS = (1000000000 * (int64_t)tim1.tv_sec + tim1.tv_nsec) -
               (1000000000 * (int64_t)tim0.tv_sec + tim0.tv_nsec);
  printf("Running time (%d threads) = %7.3fs\n", num_threads,
         (double)nS / 1000000000.0);

  return 0;
}
