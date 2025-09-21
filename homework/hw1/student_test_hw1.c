/*
 * CMSC 14300
 * Autumn 2025
 * Homework #3 Automated Tests For Voter Data Structure
 *
 */

#include <criterion/criterion.h>
#include <stdio.h>
#include <string.h>

#include "hw1.h"

#define ERR_MSG_LEN (1000)
// the format string starts with a space because the logging tool
// seems to ignore a leading \n.
#define ASSERT_FMT_STR " %s"

void do_add2_test(int x, int y, int expected, char *test_name) {
  int actual = add_two_nums(x, y);

  char err_msg[ERR_MSG_LEN];
  snprintf(err_msg, ERR_MSG_LEN - 1,
           ("\n  Parameters used in failed test: add_two_num(%d, %d)\n"
            "\n     Actual return value: %d"
            "\n     Expected return value: %d"
            "\n  The filter to run this specific test run:"
            " ./student_test_hw1 --filter \"add_two_nums/%s\""),
           x, y, actual, expected, test_name);

  cr_assert_eq(actual, expected, ASSERT_FMT_STR, err_msg);
};

Test(add_two_nums, test0) { do_add2_test(2, 2, 4, "test0"); }
Test(add_two_nums, test1) { do_add2_test(0, 2, 2, "test1"); }
Test(add_two_nums, test2) { do_add2_test(10, 0, 10, "test2"); }
Test(add_two_nums, test3) { do_add2_test(-1000, 1000, 0, "test3"); }
