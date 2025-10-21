/*
 * CMSC 14300
 * Autumn 2025
 * Lab #4: Matrix Deliverables - C file
 *
 * You will modify this file as part of the lab.
 */

// Do not remove this definition. Defining _GNU_SCORE
// allows the compiler to find the prototypes for the string
// library function strsep and the standard I/O library function getline.
#define _GNU_SOURCE

#include "matrix.h"

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Task1: print_matrix -- see matrix.h for the header comment */
void print_matrix(struct matrix_2D_int *matrix) {
  assert(matrix != NULL);
  // YOUR CODE HERE
}

/* Task 2: free_matrix -- see matrix.h for the header comment */
void free_matrix(struct matrix_2D_int *matrix) {
  assert(matrix != NULL);

  // YOUR CODE HERE
}

/* Task 3: search_matrix -- see matrix.h for the header comment */
bool search_matrix(struct matrix_2D_int *matrix, int val, int *found_row,
                   int* found_col) {
  assert(matrix != NULL);
  assert(found_row != NULL);
  assert(found_col != NULL);

  // YOUR CODE HERE
  // Replace false in the return statement with a suitable value
  return false;
}

/* Task 4: sum_matrix_rows -- see matrix.h for the header comment */
int *sum_matrix_rows(struct matrix_2D_int *matrix, int *out_len) {
  assert(matrix != NULL);
  assert(out_len != NULL);

  // YOUR CODE HERE
  // Replace NULL in the return statement with a suitable value
  return NULL;
}

/* Task 5: flip_matrix_in_place  -- see matrix.h for the header comment */
void flip_matrix_in_place(struct matrix_2D_int *matrix) {
  assert(matrix != NULL);
  assert(matrix->num_rows == matrix->num_cols);

  // YOUR CODE HERE
}

/* Task 6: flatten_matrix -- see matrix.h for the header comment */
int *flatten_matrix(struct matrix_2D_int *matrix, int *out_len) {
  assert(matrix != NULL);
  assert(out_len != NULL);

  // YOUR CODE HERE
  // Replace NULL in the return statement with a suitable value
  return NULL;
}

/**** Do NOT modify the code below this line ****/
/* matrix_2D_int: -- see matrix.h for the header comment */
struct matrix_2D_int *make_matrix(int num_rows, int num_cols) {
  assert(num_rows > 0);
  assert(num_cols > 0);

  // Allocate the structure
  struct matrix_2D_int *matrix =
      (struct matrix_2D_int*)malloc(sizeof(struct matrix_2D_int));
  if (matrix == NULL) {
    fprintf(stderr, "matrix_2D_matrix: Allocation failed\n");
    exit(1);
  }

  // Allocate the array to hold the row pointers
  matrix->num_rows = num_rows;
  matrix->num_cols = num_cols;
  matrix->data = (int**)malloc(sizeof(int*) * num_rows);
  if (matrix->data == NULL) {
    fprintf(stderr, "matrix_2D_matrix: Allocation failed\n");
    exit(1);
  }

  // Allocate the individual rows
  for (int i = 0; i < num_rows; i++) {
    // Allocate a row full of zeros.
    matrix->data[i] = (int*)calloc(num_cols, sizeof(int));
    if (matrix->data[i] == NULL) {
      fprintf(stderr, "matrix_2D_matrix: Allocation failed\n");
      exit(1);
    }
  }

  return matrix;
}

/* read_matrix_from_file -- see matrix.h for the header comment */
struct matrix_2D_int *read_matrix_from_file(char* filename) {
  int num_rows, num_cols;
  FILE* fp = fopen(filename, "r");
  if (fp == NULL) {
    fprintf(stderr, "Could not open: %s\n", filename);
    return NULL;
  }

  // The first line of the file contains the number of rows and the number of
  // columns
  if (fscanf(fp, "%d,%d\n", &num_rows, &num_cols) != 2) {
    fprintf(stderr,
            "Bad format first line should contain the number of rows and the "
            "number of columns: %s\n",
            filename);
    return NULL;
  }

  struct matrix_2D_int *matrix = make_matrix(num_rows, num_cols);
  size_t line_len = 0;
  char* line = NULL;
  for (unsigned int i = 0; i < num_rows; i++) {
    int nc = getline(&line, &line_len, fp);
    if (nc == 0) {
      fprintf(stderr,
              "File format error in Line %d: expected a non-empty line\n", i);
      exit(1);
    }
    char* start = line;
    for (unsigned int j = 0; j < num_cols; j++) {
      char* val_str = strsep(&start, ",");
      matrix->data[i][j] = atoi(val_str);
    }
  }
  // free the space allocated by getline
  free(line);
  fclose(fp);
  return matrix;
}
