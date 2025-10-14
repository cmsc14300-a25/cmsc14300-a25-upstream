/*
 * CMSC 14300
 * Autumn 2025
 * Lab #3 Automated Tests
 *
 * Run:
 *   $ make student_test_lab3
 * or just:
 *   $ make
 * to compile these tests.
 *
 * Run:
 *   $ ./student_test_lab3 -f --verbose
 * to run all the tests.
 *
 * Run:
 *   $ ./student_test_lab3 --help
 * to see the full help message for this executable.
 *
 * You will modify this file as part of the lab.
 */

#include <criterion/criterion.h>

#include "lab3.h"

/*** Tests for Task 1 ***/
/* do_co_test: do the work of one count_occurences test */
void do_co_test(int sample_nums[], int N, int target, int expected) {
  int actual = count_occurrences(sample_nums, N, target);
  // Validate the result
  cr_assert_eq(actual, expected);
}

Test(count_occurrences, test0) {
  // Test from the writeup: the target value occurs multiple times
  // in the middle of the array
  int target = 5;
  int sample_nums[] = {0, 4, target, 2, 3, target, 10, target, 27};
  // A trick for computing the length of local array variable
  // This trick does not work for dynamically allocated arrays.
  int N = (int)sizeof(sample_nums) / sizeof(int);
  int expected = 3;
  do_co_test(sample_nums, N, target, expected);
}

Test(count_occurrences, test1) {
  // Test from the writeup: the target value does not occur in the array.
  int target = 20;
  int sample_nums[] = {0, 4, 5, 2, 3, 5, 10, 5, 27};
  int N = (int)sizeof(sample_nums) / sizeof(int);
  int expected = 0;
  do_co_test(sample_nums, N, target, expected);
}

/****** ADD YOUR TESTS FOR count_occurrences HERE ******/

/*** Tests for Task 2 ***/
/* do_dm: do the work for a test of div_and_mod */
void do_dm_test(int x, int y, int expected_div, int expected_rem) {
  // Initialize the out parameter to an invalid value
  int actual_rem = -10;
  int actual = div_and_mod(x, y, &actual_rem);

  // Validate the return value
  cr_assert_eq(actual, expected_div);
  // Validate the out parameter
  cr_assert_eq(actual_rem, expected_rem);
}

Test(div_and_mod, test0) {
  // Test from the writeup: non-zero values for both
  // quotient and the remainder.
  do_dm_test(5, 2, 2, 1);
}

/****** ADD YOUR TESTS FOR div_and_mod HERE ******/

/*** Tests for Task 3 ***/
/* do_fflo_test: do the work a test for find_first_last_occurrence */
void do_fflo_test(int nums[], int N, int target, int expected_first,
                  int expected_last) {
  // Initialize the out parameters to invalid values
  int actual_first = -100000;
  int actual_last = -100000;

  find_first_last_occurrence(nums, N, target, &actual_first, &actual_last);

  // Validate the values of the out parameters
  cr_assert_eq(actual_first, expected_first);
  cr_assert_eq(actual_last, expected_last);
}

Test(find_first_last_occurrence, test0) {
  // Test from writeup: the target value occurs in the middle
  // of the array multiple times.
  int target = 5;
  int sample_nums[] = {4, target, 4, 3, 1, 10, target, 4, 1};
  // A trick for computing the length of local array variable
  // This trick does not work for dynamically allocated arrays.
  int N = (int)sizeof(sample_nums) / sizeof(int);
  int expected_first = 1;
  int expected_last = 6;

  do_fflo_test(sample_nums, N, target, expected_first, expected_last);
}

Test(find_first_last_occurrence, test1) {
  // Test from writeup: the target value does not occur in the array.
  int target = 20;
  int sample_nums[] = {4, 5, 4, 3, 1, 10, 5, 4, 1};
  int N = (int)sizeof(sample_nums) / sizeof(int);
  int expected_first = -1;
  int expected_last = -1;

  do_fflo_test(sample_nums, N, target, expected_first, expected_last);
}

/****** ADD YOUR TESTS FOR find_first_last_occurrence HERE ******/

/*** Tests for Task 4 ***/
/* do_cf_test: do the work of a test of compute_frequencies */
void do_cf_test(int lb, int ub, int nums[], int N, int expected_len,
                int expected[expected_len]) {
  // Initialize the out parameter to an invalid value
  int actual_len = -1;
  int *actual = compute_frequencies(lb, ub, nums, N, &actual_len);

  // Validate the out parameter
  cr_assert_eq(actual_len, expected_len);

  // Validate the result. This check needs to go first
  // to avoid generating a segmentation fault if the
  // function (incorrectly) returns NULL.
  cr_assert(actual != NULL);
  for (int i = 0; i < expected_len; i++) {
    // Validate the individual values in the result
    cr_assert_eq(actual[i], expected[i]);
  }

  // release the space allocated by the function
  free(actual);
}

Test(compute_frequencies, test0) {
  // Test from the writeup: both the lower and upper bounds
  // occur in the array.
  int lb = 1;
  int ub = 10;
  int sample_nums[] = {4, 5, 4, 3, lb, ub, 5, lb, 4};
  // A trick for computing the length of local array variable
  // This trick does not work for dynamically allocated arrays.
  int N = (int)sizeof(sample_nums) / sizeof(int);

  int expected[] = {2, 0, 1, 3, 2, 0, 0, 0, 0, 1};
  int M = (int)sizeof(expected) / sizeof(int);

  do_cf_test(lb, ub, sample_nums, N, M, expected);
}

Test(compute_frequencies, test1) {
  // Test from the writeup: neither the lower nor the upper bound
  // occur in the array.
  int lb = 0;
  int ub = 12;
  int sample_nums[] = {4, 5, 4, 3, 1, 10, 5, 4, 1};
  int N = (int)sizeof(sample_nums) / sizeof(int);

  int expected[] = {0, 2, 0, 1, 3, 2, 0, 0, 0, 0, 1, 0, 0};
  int M = (int)sizeof(expected) / sizeof(int);

  do_cf_test(lb, ub, sample_nums, N, M, expected);
}

/****** ADD YOUR TESTS FOR compute_frequencies HERE ******/
