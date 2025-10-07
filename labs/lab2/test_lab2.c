/*
 * CS 152, Spring 2022
 * Lab #2 Automated Tests
 *
 * Run make test_lab2 to compile these tests and ./test_lab2
 * to run these tests.  See the lab write-up for instructions
 * on how to run a subset of the tests.
 *
 * Do not modify this file.
 */

#include <assert.h>
#include <criterion/criterion.h>
#include <stdbool.h>
#include <stdio.h>

#include "lab2.h"

#define EPSILON (0.000000001)
#define ERR_MSG_LEN (1000)

/* Tests for Task 1 */
/* helper_compute_div_fraction - do the work of testing compute_div_fraction
 *
 * x, y: inputs to compute_div_fraction (x > 0, y > 0)
 * expected: the expected result
 * test_name: the test name to be used in error messages.
 */
void helper_compute_div_fraction(int x, int y, double expected,
                                 char *test_name) {
  double actual = compute_div_fraction(x, y);

  char err_msg[ERR_MSG_LEN];
  snprintf(err_msg, ERR_MSG_LEN - 1,
           ("\n  Parameters used in failed test: compute_div_fraction(%d, %d)\n"
            "\n     Actual: %f"
            "\n     Expected: %f"
            "\n  The filter to run this specific test is:"
            " --filter \"compute_div_fraction/%s\""),
           x, y, actual, expected, test_name);

  // the format string starts with a space because the logging tool
  // seems to ignore a leading \n.
  cr_assert_float_eq(actual, expected, EPSILON, " %s", err_msg);
}

Test(compute_div_fraction, test0) {
  helper_compute_div_fraction(4, 5, 0.8, "test0");
}

Test(compute_div_fraction, test1) {
  helper_compute_div_fraction(4, 4, 0.0, "test1");
}

Test(compute_div_fraction, test2) {
  helper_compute_div_fraction(1, 3, 1.0 / 3.0, "test2");
}

Test(compute_div_fraction, test3) {
  helper_compute_div_fraction(4, 3, 1.0 / 3.0, "test2");
}

/* Tests for Task 2 */
/* bool_str - convert a boolean into "true" or "false" */
char *bool_str(bool b) { return b ? "true" : "false"; }

/* helper_in_range - do the work of testing in_range_1 and in_range_2
 *
 * lb, ub, x, is_inclusive: inputs to in_range_1/in_range_2
 * expected: the expected result
 * fn_num: which function to run: 1 or 2
 * test_name: the test name to be used in error messages.
 */
void helper_in_range(double lb, double ub, double x, bool is_inclusive,
                     bool expected, int fn_num, char *test_name) {
  assert(fn_num == 1 || fn_num == 2);

  bool actual;
  char *fn_name;

  if (fn_num == 1) {
    actual = in_range_1(lb, ub, x, is_inclusive);
    fn_name = "in_range_1";
  } else {
    actual = in_range_2(lb, ub, x, is_inclusive);
    fn_name = "in_range_2";
  }

  char err_msg[ERR_MSG_LEN];
  snprintf(err_msg, ERR_MSG_LEN - 1,
           ("\n  Parameters used in failed test: "
            " %s(%f, %f, %f, %s)\n"
            "\n     Actual: %s"
            "\n     Expected: %s"
            "\n  The filter to run this specific test is:"
            " --filter \"%s/%s\""),
           fn_name, lb, ub, x, bool_str(is_inclusive), bool_str(actual),
           bool_str(expected), fn_name, test_name);

  if (expected) {
    cr_assert(actual, " %s", err_msg);
  } else {
    cr_assert(!actual, " %s", err_msg);
  }
}

Test(in_range_1, middle_non_inclusive) {
  // Check a value in the middle of the range w/ inclusive set to false
  helper_in_range(0.0, 1.0, 0.5, false, true, 1, "middle_non_inclusive");
}

Test(in_range_1, middle_inclusive) {
  // Check a value in the middle of the range w/ inclusive set to true
  helper_in_range(0.0, 1.0, 0.5, true, true, 1, "middle_inclusive");
}

Test(in_range_1, lb_non_inclusive) {
  // Check value of lb in range w/ inclusive set to false
  helper_in_range(0.0, 1.0, 0.0, false, false, 1, "lb_non_inclusive");
}

Test(in_range_1, lb_inclusive) {
  // Check value of lb in range w/ inclusive set to true
  helper_in_range(0.0, 1.0, 0.0, true, true, 1, "lb_inclusive");
}

Test(in_range_1, ub_non_inclusive) {
  // Check value of ub in range w/ inclusive set to false
  helper_in_range(0.0, 1.0, 1.0, false, false, 1, "ub_non_inclusive");
}

Test(in_range_1, ub_inclusive) {
  // Check value of ub in range w/ inclusive set to true
  helper_in_range(0.0, 1.0, 0.0, true, true, 1, "ub_inclusive");
}

Test(in_range_1, less_than_lb_non_inclusive) {
  // Check a value of that is less than the lb in range w/
  // inclusive set to false
  helper_in_range(0.0, 1.0, -0.5, false, false, 1,
                  "less_than_lb_non_inclusive");
}

Test(in_range_1, less_than_lb_inclusive) {
  // Check a value that is less than the lb in range w/
  // inclusive set to true
  helper_in_range(0.0, 1.0, -0.5, true, false, 1, "less_than_lb_inclusive");
}

Test(in_range_1, greater_than_ub_non_inclusive) {
  // Check a value of that is greater than the lb in range w/
  // inclusive set to false
  helper_in_range(0.0, 1.0, 2.0, false, false, 1,
                  "greater_than_ub_non_inclusive");
}

Test(in_range_1, greater_than_ub_inclusive) {
  // Check a value that is greater than the lb in range w/
  // inclusive set to true
  helper_in_range(0.0, 1.0, 2.0, true, false, 1, "greater_than_ub_inclusive");
}

/* Tests for Task 3 */
Test(in_range_2, middle_non_inclusive) {
  // Check a value in the middle of the range w/ inclusive set to false
  helper_in_range(0.0, 1.0, 0.5, false, true, 2, "middle_non_inclusive");
}

Test(in_range_2, middle_inclusive) {
  // Check a value in the middle of the range w/ inclusive set to true
  helper_in_range(0.0, 1.0, 0.5, true, true, 2, "middle_inclusive");
}

Test(in_range_2, lb_non_inclusive) {
  // Check value of lb in range w/ inclusive set to false
  helper_in_range(0.0, 1.0, 0.0, false, false, 2, "lb_non_inclusive");
}

Test(in_range_2, lb_inclusive) {
  // Check value of lb in range w/ inclusive set to true
  helper_in_range(0.0, 1.0, 0.0, true, true, 2, "lb_inclusive");
}

Test(in_range_2, ub_non_inclusive) {
  // Check value of ub in range w/ inclusive set to false
  helper_in_range(0.0, 1.0, 1.0, false, false, 2, "ub_non_inclusive");
}

Test(in_range_2, ub_inclusive) {
  // Check value of ub in range w/ inclusive set to true
  helper_in_range(0.0, 1.0, 0.0, true, true, 2, "ub_inclusive");
}

Test(in_range_2, less_than_lb_non_inclusive) {
  // Check a value of that is less than the lb in range w/
  // inclusive set to false
  helper_in_range(0.0, 1.0, -0.5, false, false, 2,
                  "less_than_lb_non_inclusive");
}

Test(in_range_2, less_than_lb_inclusive) {
  // Check a value that is less than the lb in range w/
  // inclusive set to true
  helper_in_range(0.0, 1.0, -0.5, true, false, 2, "less_than_lb_inclusive");
}

Test(in_range_2, greater_than_ub_non_inclusive) {
  // Check a value of that is greater than the lb in range w/
  // inclusive set to false
  helper_in_range(0.0, 1.0, 2.0, false, false, 2,
                  "greater_than_ub_non_inclusive");
}

Test(in_range_2, greater_than_ub_inclusive) {
  // Check a value that is greater than the lb in range w/
  // inclusive set to true
  helper_in_range(0.0, 1.0, 2.0, true, false, 2, "greater_than_ub_inclusive");
}

/* Tests for Task 4 */
/* helper_clip - do the work of testing clip
 *
 * x, lb, ub: inputs to clip
 * expected: the expected result
 * test_name: the test name to be used in error messages.
 */
void helper_clip(double x, double lb, double ub, double expected,
                 char *test_name) {
  double actual = clip(x, lb, ub);

  char err_msg[ERR_MSG_LEN];
  snprintf(err_msg, ERR_MSG_LEN - 1,
           ("\n  Parameters used in failed test: clip(%f, %f, %f)\n"
            "\n     Actual: %f"
            "\n     Expected: %f"
            "\n  The filter to run this specific test is:"
            " --filter \"clip/%s\""),
           x, lb, ub, actual, expected, test_name);

  cr_assert_float_eq(actual, expected, EPSILON, " %s", err_msg);
}

Test(clip, equal_lower) {
  // test value equal to the lower bound
  helper_clip(0.0, 0.0, 4.0, 0.0, "equal_lower");
}

Test(clip, less_than_lower) {
  // test clip to lower bound
  helper_clip(-1.0, 0.0, 4.0, 0.0, "less_than_lower");
}

Test(clip, equal_upper) {
  // test value equal to the upper bound
  helper_clip(4.0, 0.0, 4.0, 4.0, "equal_upper");
}

Test(clip, greater_than_upper) {
  // test clip to upper bound
  helper_clip(5.0, 0.0, 4.0, 4.0, "greater_than_upper");
}

Test(clip, middle) {
  // test value in the middle of the range
  helper_clip(2.5, 0.0, 4.0, 2.5, "middle");
}

/* Tests for Task 5 */
/* helper_compute_leonardo - do the work of testing compute_leonardo
 *
 * n: input to leonardo (n > 0)
 * expected: the expected result
 * test_name: the test name to be used in error messages.
 */
void helper_compute_leonardo(int n, int expected, char *test_name) {
  int actual = compute_leonardo(n);
  char err_msg[ERR_MSG_LEN];

  snprintf(err_msg, ERR_MSG_LEN - 1,
           ("\n  Parameters used in failed test: compute_leonardo(%d)\n"
            "\n     Actual: %d"
            "\n     Expected: %d"
            "\n  The filter to run this specific test is:"
            " --filter \"compute_leonardo/%s\""),
           n, actual, expected, test_name);

  cr_assert_eq(actual, expected, " %s", err_msg);
}

Test(compute_leonardo, test0) { helper_compute_leonardo(0, 1, "test0"); }

Test(compute_leonardo, test1) { helper_compute_leonardo(1, 1, "test1"); }

Test(compute_leonardo, test2) { helper_compute_leonardo(2, 3, "test2"); }

Test(compute_leonardo, test3) { helper_compute_leonardo(18, 8361, "test3"); }
