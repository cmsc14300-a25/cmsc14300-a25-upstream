/*
 * CMSC 14300
 * Autumn 2025
 * Lab #4: Matrix Header File
 *
 * Do not modify this file
 */

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Data structure for representing two-dimensional
// arrays of integers.
struct matrix_2D_int {
  int num_rows;
  int num_cols;
  int** data;
};

/* PROVIDED
 * make_2D_matrix: Create 2D heap-allocated matrix of zeros
 *
 * num_rows: the number of rows in the matrix
 * num_cols: the number of columns in the matrix
 *
 * Returns: A pointer to a 2D matrix
 */
struct matrix_2D_int *make_matrix(int num_rows, int num_cols);

/* PROVIDED
 * read_matrix_from_file: Read a 2D matrix from a file
 *
 * filename: the name of the file containing the matrix
 *
 * Returns: a pointer to a 2D matrix or NULL, if the file does not exist
 */
struct matrix_2D_int *read_matrix_from_file(char* filename);

/*
 * free_matrix: Free a 2D matrix structure.
 *
 * matrix: the matrix to free
 *
 * Returns: nothing
 */
void free_matrix(struct matrix_2D_int *matrix);

/*
 * print_matrix: Print a 2D matrix
 *
 * matrix: the matrix to print
 *
 * Returns: nothing
 */
void print_matrix(struct matrix_2D_int *matrix);

/*
 * search_matrix: Performs a row-major-order search for a value in a 2D matrix
 *
 * matrix: the matrix to search
 * val: the value to search for
 * found_row: the row in which the first instance of val was found
 *   (out parameter)
 * found_col: the column in which the first instance val was found
 *   (out parameter)
 *
 * Returns: true if val is in matrix, false otherwise
 */
bool search_matrix(struct matrix_2D_int *matrix, int val, int *found_row,
                   int *found_col);

/*
 * sum_matrix_rows: Sum the values in each row of a 2D matrix
 *
 * matrix: the matrix
 * out_len: the length of the output array (out parameter)
 *
 * Returns: An array of sums, one for each row
 */
int *sum_matrix_rows(struct matrix_2D_int *matrix, int *out_len);

/*
 * flip_matrix_in_place: the values in a square matrix in place.
 *
 * matrix: the matrix to flip
 *
 * Returns: nothing
 */
void flip_matrix_in_place(struct matrix_2D_int *matrix);

/*
 * flatten_matrix: Flatten a 2D matrix into a 1D array in row-major order
 *
 * matrix: the matrix to flatten
 * out_len: the length of the output array (out parameter)
 *
 * Returns: A flattened version of matrix
 */
int *flatten_matrix(struct matrix_2D_int *matrix, int *out_len);
