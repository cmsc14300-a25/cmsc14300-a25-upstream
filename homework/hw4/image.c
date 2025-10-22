/*
 * CMSC 14300
 * Autumn 2025
 * Homework #4: Image implementation
 *
 * You will modify this file.
 */

#include "image.h"

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "util.h"

/* Task 1: create_blk_image -- see image.h for the header comment */
struct image *create_blk_image(int height, int width) {
  assert(height > 0);
  assert(width > 0);

  // YOUR CODE HERE
  // Replace NULL with a suitable return value
  return NULL;
}

/* Task 2: free_image  -- see image.h for the header comment */
void free_image(struct image *img) {
  // YOUR CODE HERE
}

/* Task 3: print_image  -- see image.h for the header comment */
void print_image(struct image *img) {
  // YOUR CODE HERE
}

/* Task 4: create_negative  -- see image.h for the header comment */
struct image *create_negative(struct image *input) {
  // YOUR CODE HERE
  // Replace NULL with a suitable return value
  return NULL;
}

/* Task 5: create_greyscale  -- see image.h for the header comment */
struct image *create_greyscale(struct image *input) {
  // YOUR CODE HERE
  // Replace NULL with a suitable return value
  return NULL;
}

/* Task 6: blur  -- see image.h for the header comment */
struct image *blur(struct image *input, int size) {
  // Size must be odd
  assert((size > 0) && (size % 2 == 1));

  // YOUR CODE HERE
  // Replace NULL with a suitable return value
  return NULL;
}
