/*
 * CMSC 14300
 * Autumn 2025
 * Homework #2 Automated Tests
 *
 * Run make test_hw2 or just make to compile these tests and
 * ./test_hw2 to run these tests.  See the homework write-up for
 * instructions on how to run a subset of the tests.
 *
 * Do not modify this file.
 */

#include <criterion/criterion.h>
#include <stdbool.h>
#include <stdio.h>

#include "hw2.h"

#define ERR_MSG_LEN (1000)
#define EPSILON (0.01)

// the format string starts with a space because the logging tool
// seems to ignore a leading \n.
#define ASSERT_FMT_STR " %s"

/* Helper function */
/* bool_str - convert a boolean into "true" or "false" */
char *bool_str(bool b) { return b ? "true" : "false"; }

/* Tests for Exercise 1 */

/* helper_are_friendly - do the work of testing are_friendly
 *
 * num1, num2, divisor: inputs to are_friendly
 * expected: the expected result
 * test_name: the test name to be used in error messages.
 */
void helper_are_friendly(int num1, int num2, int divisor, bool expected,
                         char *test_name) {
  bool actual = are_friendly(num1, num2, divisor);

  char err_msg[ERR_MSG_LEN];
  snprintf(err_msg, ERR_MSG_LEN - 1,
           ("\n  Parameters used in failed test: are_friendly(%d, %d, %d)\n"
            "\n     Actual: %s"
            "\n     Expected: %s"
            "\n  The filter to run this specific test is: are_friendly/%s"),
           num1, num2, divisor, bool_str(actual), bool_str(expected),
           test_name);

  if (expected) {
    cr_assert(actual, ASSERT_FMT_STR, err_msg);
  } else {
    cr_assert(!actual, ASSERT_FMT_STR, err_msg);
  }
}

Test(are_friendly, test0) { helper_are_friendly(1, 1, 1, true, "test0"); }

Test(are_friendly, test1) { helper_are_friendly(4, 4, 1, true, "test1"); }

Test(are_friendly, test2) { helper_are_friendly(4, 4, 4, true, "test2"); }

Test(are_friendly, test3) { helper_are_friendly(2, 4, 2, true, "test3"); }

Test(are_friendly, test4) { helper_are_friendly(4, 2, 2, true, "test4"); }

Test(are_friendly, test5) { helper_are_friendly(2, 4, 4, false, "test5"); }

Test(are_friendly, test6) { helper_are_friendly(4, 2, 4, false, "test6"); }

Test(are_friendly, test7) { helper_are_friendly(12, 15, 1, true, "test7"); }

Test(are_friendly, test8) { helper_are_friendly(12, 15, 2, false, "test8"); }

Test(are_friendly, test9) { helper_are_friendly(12, 15, 3, true, "test9"); }

Test(are_friendly, test10) { helper_are_friendly(15, 12, 3, true, "test10"); }

Test(are_friendly, test11) { helper_are_friendly(12, 15, 4, false, "test11"); }

Test(are_friendly, test12) { helper_are_friendly(12, 15, 5, false, "test12"); }

/* Tests for Exercise 2 */
/* helper_compute_degree_of_friendship - do the work of testing
 * compute_degree_of_friendship
 *
 * num1, num2: inputs to compute_degree_of_friendship
 * expected: the expected result
 * test_name: the test name to be used in error messages.
 */
void helper_compute_degree_of_friendship(int num1, int num2, int expected,
                                         char *test_name) {
  int actual = compute_degree_of_friendship(num1, num2);

  char err_msg[ERR_MSG_LEN];
  snprintf(err_msg, ERR_MSG_LEN - 1,
           ("\n  Parameters used in failed test: "
            "compute_degree_of_friendship(%d, %d)\n"
            "\n     Actual: %d"
            "\n     Expected: %d"
            "\n  The filter to run this specific test is: "
            "compute_degree_of_friendship/%s"),
           num1, num2, actual, expected, test_name);

  cr_assert_eq(actual, expected, ASSERT_FMT_STR, err_msg);
}

Test(compute_degree_of_friendship, test0) {
  helper_compute_degree_of_friendship(1, 1, 1, "test0");
}

Test(compute_degree_of_friendship, test1) {
  helper_compute_degree_of_friendship(1, 2, 1, "test1");
}

Test(compute_degree_of_friendship, test2) {
  helper_compute_degree_of_friendship(2, 1, 1, "test2");
}

Test(compute_degree_of_friendship, test3) {
  helper_compute_degree_of_friendship(2, 4, 2, "test3");
}

Test(compute_degree_of_friendship, test4) {
  helper_compute_degree_of_friendship(4, 2, 2, "test4");
}

Test(compute_degree_of_friendship, test5) {
  helper_compute_degree_of_friendship(3, 5, 1, "test5");
}

Test(compute_degree_of_friendship, test6) {
  helper_compute_degree_of_friendship(5, 3, 1, "test6");
}

Test(compute_degree_of_friendship, test7) {
  helper_compute_degree_of_friendship(12, 15, 2, "test7");
}

Test(compute_degree_of_friendship, test8) {
  helper_compute_degree_of_friendship(15, 12, 2, "test8");
}

Test(compute_degree_of_friendship, test9) {
  helper_compute_degree_of_friendship(12, 36, 6, "test9");
}

Test(compute_degree_of_friendship, test10) {
  helper_compute_degree_of_friendship(36, 12, 6, "test10");
}

/* Tests for Exercise 3 */
/* helper_goldschmidt - do the work of testing goldschmidt
 *
 * num1, num2: inputs to goldschmidt
 * expected: the expected result
 * test_name: the test name to be used in error messages.
 */
void helper_goldschmidt(double N, double est, int max_iters, double tol,
                        float expected, char *test_name) {
  float actual = goldschmidt(N, est, max_iters, tol);

  char err_msg[ERR_MSG_LEN];
  snprintf(err_msg, ERR_MSG_LEN - 1,
           ("\n  Parameters used in failed test: goldschmidt(%f, %f, %d, %f)\n"
            "\n     Actual: %f"
            "\n     Expected: %f"
            "\n  The filter to run this specific test is: goldschmidt/%s"),
           N, est, max_iters, tol, actual, expected, test_name);

  cr_assert_float_eq(actual, expected, EPSILON, ASSERT_FMT_STR, err_msg);
}
Test(goldschmidt, test0) {
  helper_goldschmidt(4, 0.4, 1, 0.001, 1.88, "test0");
}

Test(goldschmidt, test1) {
  helper_goldschmidt(4, 0.4, 2, 0.001, 1.99, "test1");
}

Test(goldschmidt, test2) {
  helper_goldschmidt(4, 0.4, 3, 0.001, 1.99, "test2");
}

Test(goldschmidt, test3) { helper_goldschmidt(4, 0.4, 4, 0.001, 2.0, "test3"); }

Test(goldschmidt, test4) { helper_goldschmidt(4, 0.4, 10, 0.001, 2, "test4"); }

Test(goldschmidt, test5) {
  helper_goldschmidt(4, 0.6, 1, 0.001, 1.87, "test5");
}

Test(goldschmidt, test6) {
  helper_goldschmidt(4, 0.6, 2, 0.001, 1.98, "test6");
}

Test(goldschmidt, test7) {
  helper_goldschmidt(4, 0.6, 3, 0.001, 1.99, "test7");
}

Test(goldschmidt, test8) { helper_goldschmidt(4, 0.6, 10, 0.001, 2, "test8"); }

Test(goldschmidt, test9) { helper_goldschmidt(4, 0.6, 10, 0.5, 1.87, "test9"); }

Test(goldschmidt, test10) {
  helper_goldschmidt(4, 0.6, 10, 0.2, 1.98, "test10");
}

Test(goldschmidt, test11) {
  helper_goldschmidt(4, 0.6, 10, 0.1, 1.99, "test11");
}

/* Tests for Exercise 4 */
/* helper_has_even_parity - do the work of testing has_even_parity
 *
 * num1: input to has_even_parity
 * expected: the expected result
 * test_name: the test name to be used in error messages.
 */
void helper_has_even_parity(int num, bool expected, char *test_name) {
  bool actual = has_even_parity(num);

  char err_msg[ERR_MSG_LEN];
  snprintf(err_msg, ERR_MSG_LEN - 1,
           ("\n  Parameters used in failed test: has_even_parity(%d)\n"
            "\n     Actual: %s"
            "\n     Expected: %s"
            "\n  The filter to run this specific test is: has_even_parity/%s"),
           num, bool_str(actual), bool_str(expected), test_name);

  if (expected) {
    cr_assert(actual, ASSERT_FMT_STR, err_msg);
  } else {
    cr_assert(!actual, ASSERT_FMT_STR, err_msg);
  }
}
Test(has_even_parity, test0) { helper_has_even_parity(1, false, "test0"); }

Test(has_even_parity, test1) { helper_has_even_parity(2, true, "test1"); }

Test(has_even_parity, test2) { helper_has_even_parity(3, false, "test2"); }

Test(has_even_parity, test3) { helper_has_even_parity(4, true, "test3"); }

Test(has_even_parity, test4) { helper_has_even_parity(100, true, "test4"); }

Test(has_even_parity, test5) { helper_has_even_parity(101, false, "test5"); }


/* Tests for Exercise 5 */
/* helper_find_index_of_lowest_1 - do the work of testing find_index_of_lowest_1
 *
 * num: input to find_index_of_lowest_1
 * expected: the expected result
 * test_name: the test name to be used in error messages.
 */
void helper_find_index_of_lowest_1(unsigned int num, int expected,
                                   char *test_name) {
  int actual = find_index_of_lowest_1(num);

  char err_msg[ERR_MSG_LEN];
  snprintf(err_msg, ERR_MSG_LEN - 1,
           ("\n  Parameters used in failed test: find_index_of_lowest_1(%d)\n"
            "\n     Actual: %d"
            "\n     Expected: %d"
            "\n  The filter to run this specific test is: "
            "find_index_of_lowest_1/%s"),
           num, actual, expected, test_name);

  cr_assert_eq(actual, expected, ASSERT_FMT_STR, err_msg);
}

Test(find_index_of_lowest_1, test0) {
  helper_find_index_of_lowest_1(1, 0, "test0");
}

Test(find_index_of_lowest_1, test1) {
  helper_find_index_of_lowest_1(2, 1, "test1");
}

Test(find_index_of_lowest_1, test2) {
  helper_find_index_of_lowest_1(3, 0, "test2");
}

Test(find_index_of_lowest_1, test3) {
  helper_find_index_of_lowest_1(4, 2, "test3");
}

Test(find_index_of_lowest_1, test4) {
  helper_find_index_of_lowest_1(22, 1, "test4");
}

Test(find_index_of_lowest_1, test5) {
  helper_find_index_of_lowest_1(0xfc00, 10, "test5");
}

Test(find_index_of_lowest_1, test6) {
  helper_find_index_of_lowest_1(0xa000, 13, "test6");
}

Test(find_index_of_lowest_1, test7) {
  helper_find_index_of_lowest_1(0x80000000, 31, "test7");
}

/* Tests for Exercise 6 */
/* helper_find_index_of_highest_1 - do the work of testing
 * find_index_of_highest_1
 *
 * num: input to find_index_of_highest_1
 * expected: the expected result
 * test_name: the test name to be used in error messages.
 */
void helper_find_index_of_highest_1(unsigned int num, int expected,
                                    char *test_name) {
  int actual = find_index_of_highest_1(num);

  char err_msg[ERR_MSG_LEN];
  snprintf(err_msg, ERR_MSG_LEN - 1,
           ("\n  Parameters used in failed test: find_index_of_highest_1(%d)\n"
            "\n     Actual: %d"
            "\n     Expected: %d"
            "\n  The filter to run this specific test is: "
            "find_index_of_highest_1/%s"),
           num, actual, expected, test_name);

  cr_assert_eq(actual, expected, ASSERT_FMT_STR, err_msg);
}

Test(find_index_of_highest_1, test0) {
  helper_find_index_of_highest_1(1, 0, "test0");
}

Test(find_index_of_highest_1, test1) {
  helper_find_index_of_highest_1(2, 1, "test1");
}

Test(find_index_of_highest_1, test2) {
  helper_find_index_of_highest_1(3, 1, "test2");
}

Test(find_index_of_highest_1, test3) {
  helper_find_index_of_highest_1(4, 2, "test3");
}

Test(find_index_of_highest_1, test4) {
  helper_find_index_of_highest_1(20, 4, "test4");
}

Test(find_index_of_highest_1, test5) {
  helper_find_index_of_highest_1(100, 6, "test5");
}

Test(find_index_of_highest_1, test6) {
  helper_find_index_of_highest_1(1000, 9, "test6");
}

Test(find_index_of_highest_1, test7) {
  helper_find_index_of_highest_1(10000, 13, "test7");
}

/* Tests for Exercise 6 */
/* helper_set_bits_between - do the work of testing set_bits_between
 *
 * num: input to set_bits_between
 * expected: the expected result

 */
void helper_set_bits_between(unsigned int num, unsigned int expected,
                             char *test_name) {
  int actual = set_bits_between(num);

  char err_msg[ERR_MSG_LEN];
  snprintf(err_msg, ERR_MSG_LEN - 1,
           ("\n  Parameters used in failed test: set_bits_between(%d)\n"
            "\n     Actual: %d"
            "\n     Expected: %d"
            "\n  The filter to run this specific test is: "
            "set_bits_between/%s"),
           num, actual, expected, test_name);

  cr_assert_eq(actual, expected, ASSERT_FMT_STR, err_msg);
}

Test(set_bits_between, test0) { helper_set_bits_between(0x0, 0, "test0"); }

Test(set_bits_between, test1) {
  helper_set_bits_between(0xffffffff, 0xffffffff, "test1");
}

Test(set_bits_between, test2) {
  helper_set_bits_between(0x1008, 0x1ff8, "test2");
}

Test(set_bits_between, test3) {
  helper_set_bits_between(0x440, 0x7c0, "test3");
}

Test(set_bits_between, test4) {
  helper_set_bits_between(0xC0000420, 0xffffffe0, "test4");
}
