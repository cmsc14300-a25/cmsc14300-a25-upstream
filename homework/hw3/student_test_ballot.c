/*
 * CMSC 14300
 * Autumn 2025
 * Homework #3 Automated Tests For Voter Data Structure
 *
 */

#include <criterion/criterion.h>
#include <stdbool.h>
#include <stdio.h>

#include "ballot.h"
#include "util.h"

#define ERR_MSG_LEN (1000)
#define EPSILON (0.01)

// the format string starts with a space because the logging tool
// seems to ignore a leading \n.
#define ASSERT_FMT_STR " %s"

/*** Tests for Task 1 ***/
/* do_fifv_test: do the work of one test for find_index_first_viable */
void do_fifv_test(char *viable_candidates[], int num_candidates, char *ballot[],
                  int expected) {
  int actual =
      find_index_first_viable(viable_candidates, num_candidates, ballot);

  // Validate the result
  cr_assert_eq(actual, expected);
}

Test(find_index_first_viable, test0) {
  // Test from writeup: first viable candidate appears in the middle
  // of the list of ranked choice votes.
  char *viable_candidates[] = {"red",  "purple", "blue", "light blue",
                               "pink", "yellow", "green"};
  char *ballot[] = {"maroon", "black", "yellow", "purple", "green"};
  // A trick for computing the length of local array variable
  // This trick does not work for dynamically allocated arrays.
  int num_candidates = (int)sizeof(viable_candidates) / sizeof(char *);
  int expected = 5;

  do_fifv_test(viable_candidates, num_candidates, ballot, expected);
}

Test(find_index_first_viable, test1) {
  // Test from writeup: ballot does not contain any viable candidates
  char *viable_candidates[] = {"red",  "purple", "blue", "light blue",
                               "pink", "yellow", "green"};
  char *ballot[] = {"gray", "black", "white", "", ""};
  // A trick for computing the length of local array variable
  // This trick does not work for dynamically allocated arrays.
  int N = (int)sizeof(viable_candidates) / sizeof(char *);
  int expected = -1;

  do_fifv_test(viable_candidates, N, ballot, expected);
}

// ADD YOUR Task 1 tests here.

/*** Tests for Task 2 ***/
void do_bts_test(char *ballot[], char *expected) {
  char *actual = ballot_to_str(ballot);
  cr_assert(actual != NULL);
  cr_assert(strcmp(expected, actual) == 0);
}

Test(ballot_to_str, test0) {
  char *ballot[] = {"maroon", "black", "yellow", "purple", "green"};
  char *expected = "maroon,black,yellow,purple,green";
  do_bts_test(ballot, expected);
}

Test(ballot_to_str, test1) {
  char *ballot[] = {"gray", "black", "white", "", ""};
  char *expected = "gray,black,white,,";
  do_bts_test(ballot, expected);
}

// ADD YOUR Task 2 tests here.
