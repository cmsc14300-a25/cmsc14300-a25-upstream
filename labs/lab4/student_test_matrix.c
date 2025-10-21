/*
 * CMSC 14300
 * Autumn 2025
 * Lab #4 Partial Automated Tests
 *
 * Run:
 *   $ make student_text_matrix
 * or just:
 *   $ make
 * to compile these tests.
 *
 * Run:
 *   $ ./student_text_matrix -f --verbose
 * to run all the tests.
 *
 * Run:
 *   $ ./student_text_matrix --help
 * to see the full help message for this executable.
 *
 * You will modify this file as part of the lab.
 */

#include <criterion/criterion.h>
#include <stdbool.h>
#include <stdio.h>

#include "matrix.h"

/* Tests for Task 3 */
void do_search_test(struct matrix_2D_int *m, int val, int expected_row,
                    int expected_col) {
  // Function should return true, if the expected row and column are
  // not -1.
  bool expected_result = (expected_row != -1) && (expected_col != -1);
  // Initialize to invalid values to make errors
  // easier to catch;
  int actual_row = -1000;
  int actual_col = -1000;

  bool actual_result = search_matrix(m, val, &actual_row, &actual_col);

  // validate the return value
  cr_assert_eq(expected_result, actual_result);

  // validate the row out parameter
  cr_assert_eq(expected_row, actual_row);

  // validate the column out parameter
  cr_assert_eq(expected_col, actual_col);
}

Test(search_matrix, test0) {
  // Matrix contains one copy of the target value
  struct matrix_2D_int *m =
      read_matrix_from_file("sample_matrices/sample_3_4.txt");
  do_search_test(m, 10, 0, 1);
  free_matrix(m);
}

Test(search_matrix, test1) {
  // Matrix contains eight copies of the target value
  struct matrix_2D_int *m =
      read_matrix_from_file("sample_matrices/sample_3_4.txt");
  do_search_test(m, 0, 0, 0);
  free_matrix(m);
}

Test(search_matrix, test2) {
  // Matrix contains zero copies of the target value
  struct matrix_2D_int *m =
      read_matrix_from_file("sample_matrices/sample_3_4.txt");
  do_search_test(m, 50, -1, -1);
  free_matrix(m);
}

void do_sr_test(struct matrix_2D_int *m, int *expected_vals) {
  // Initialize to an invalid value to make it easy to identify errors.
  int len = -1000;
  int *actual_vals = sum_matrix_rows(m, &len);

  // validate the expected length
  cr_assert_eq(len, m->num_rows);

  // validate the values
  cr_assert(actual_vals != NULL);
  for (unsigned int i = 0; i < len; i++) {
    cr_assert_eq(expected_vals[i], actual_vals[i]);
  }
}

/* Tests for Task 4 */
Test(sum_matrix_rows, test0) {
  // Rectangular matrix with some values
  struct matrix_2D_int *m =
      read_matrix_from_file("sample_matrices/sample_3_4.txt");

  int expected[] = {10, 20, 70};
  do_sr_test(m, expected);
  free_matrix(m);
}

/* Tests for Task 5 */
void do_flip_test(char *input_filename, char *expected_filename) {
  struct matrix_2D_int *actual = read_matrix_from_file(input_filename);
  struct matrix_2D_int *expected = read_matrix_from_file(expected_filename);
  flip_matrix_in_place(actual);

  // Verify the result
  for (int i = 0; i < expected->num_rows; i++) {
    for (int j = 0; j < expected->num_cols; j++) {
      cr_assert_eq(expected->data[i][j], actual->data[i][j]);
    }
  }
  free_matrix(actual);
  free_matrix(expected);
}

Test(flip_matrix_in_place, test0) {
  do_flip_test("sample_matrices/sample_square.txt",
               "sample_matrices/sample_square_flipped.txt");
}

/* Tests for Task 6 */
void do_flatten_test(struct matrix_2D_int *m, int *expected_vals) {
  // Initialize to an invalid value
  int actual_len = -1000;
  int *actual_vals = flatten_matrix(m, &actual_len);

  // Verify the length
  cr_assert_eq(m->num_rows * m->num_cols, actual_len);

  // Check the values
  cr_assert(actual_vals != NULL);
  for (unsigned int i = 0; i < actual_len; i++) {
    cr_assert_eq(expected_vals[i], actual_vals[i]);
  }
}

Test(flatten_matrix, test1) {
  // Rectangular matrix with some non-zero values
  struct matrix_2D_int *m =
      read_matrix_from_file("sample_matrices/sample_3_4.txt");
  int expected[] = {0, 10, 0, 0, 20, 0, 0, 0, 0, 30, 0, 40};
  do_flatten_test(m, expected);
  free_matrix(m);
}
