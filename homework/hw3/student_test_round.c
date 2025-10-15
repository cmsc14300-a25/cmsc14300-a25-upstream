/*
 * CMSC 14300
 * Autumn 2025
 * Homework #3 Automated Tests For Voter Data Structure
 *
 */

#include <criterion/criterion.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "ballot.h"
#include "round.h"
#include "util.h"

#define ERR_MSG_LEN (1000)
#define EPSILON (0.01)

// the format string starts with a space because the logging tool
// seems to ignore a leading \n.
#define ASSERT_FMT_STR " %s"

/*** Tests for count_votes ***/
/* do_cv_test: do the work of one test of count_votes */
void do_cv_test(char *ballots_filename, char *candidates[],
                int num_viable_candidates, int *expected_counts) {
  int num_ballots;
  char ***ballots = read_ballots_from_file(ballots_filename, &num_ballots);
  cr_assert(ballots != NULL);

  int actual_counts[num_viable_candidates];
  for (unsigned int i = 0; i < num_viable_candidates; i++) {
    // set the ith entry to a large invalid value
    actual_counts[i] = -1000;
  }

  count_votes(candidates, num_viable_candidates, ballots, num_ballots,
              actual_counts);

  // validate the vote counts
  for (unsigned int i = 0; i < num_viable_candidates; i++) {
    cr_assert_eq(expected_counts[i], actual_counts[i]);
  }

  free_ballots(ballots, num_ballots);
}

Test(count_votes, test0) {
  // Test from the writeup: four votes with at least one viable candidate
  // and one exhausted ballot.
  char *candidates[] = {"red", "blue"};
  int num_viable_candidates = sizeof(candidates) / sizeof(char *);
  int expected_counts[] = {2, 2};
  do_cv_test("tests/ballots_0.txt", candidates, num_viable_candidates,
             expected_counts);
}

// ADD YOUR Task 4 tests here.

/**** Test code for find_winner ****/
void do_fw(int *counts, int num_counts, int expected_idx) {
  int expected_num_available_votes = 0;
  for (unsigned int i = 0; i < num_counts; i++) {
    expected_num_available_votes += counts[i];
  }
  int num_available_votes;
  int actual_idx = find_winner(counts, num_counts, &num_available_votes);
  cr_assert_eq(expected_num_available_votes, num_available_votes);
  cr_assert_eq(expected_idx, actual_idx);
}

Test(find_winner, test0) {
  // Test from writeup: odd number of ballots, there is a winner.
  int counts[] = {2, 4, 1};
  int num_counts = sizeof(counts) / sizeof(int);
  int expected_idx = 1;
  do_fw(counts, num_counts, expected_idx);
}

Test(find_winner, test1) {
  // Test from writeup: even number of ballots, there is not a winner.
  int counts[] = {1, 0, 1, 2};
  int num_counts = sizeof(counts) / sizeof(int);
  int expected_idx = -1;
  do_fw(counts, num_counts, expected_idx);
}

// ADD YOUR Task 5 tests here.

/**** Test code for swap_lowest ****/
void do_sl_test(char *candidates[], int num_viable_candidates, int counts[],
                char *expected_candidates[], int expected_counts[]) {
  swap_lowest(candidates, num_viable_candidates, counts);

  for (unsigned int i = 0; i < num_viable_candidates; i++) {
    // candidates is modified in place
    cr_assert(candidates[i] != NULL);
    cr_assert(strcmp(expected_candidates[i], candidates[i]) == 0);
    // counts is modified in place.
    cr_assert_eq(expected_counts[i], counts[i]);
  }
}

Test(swap_lowest, test0) {
  // swap a candidate in the middle
  char *candidates[] = {"red", "green", "blue", "purple"};
  int num_viable_candidates = sizeof(candidates) / sizeof(char *);
  int counts[] = {4, 1, 3, 5};
  char *expected_candidates[] = {"red", "purple", "blue", "green"};
  int expected_counts[] = {4, 5, 3, 1};

  do_sl_test(candidates, num_viable_candidates, counts, expected_candidates,
             expected_counts);
}

Test(swap_lowest, test1) {
  // swap a candidate in the middle
  char *candidates[] = {"red", "green", "blue", "purple"};
  int num_viable_candidates = sizeof(candidates) / sizeof(char *);
  int counts[] = {4, 1, 1, 5};
  char *expected_candidates[] = {"red", "green", "purple", "blue"};
  int expected_counts[] = {4, 1, 5, 1};

  do_sl_test(candidates, num_viable_candidates, counts, expected_candidates,
             expected_counts);
}
// ADD YOUR Task 6 tests here.

/**** Test code for run_round ****/
void do_rr_test(char *ballots_filename, char *candidates[],
                int num_viable_candidates, struct election_info expected,
                int expected_winner) {
  // construct the argument to run_round
  struct election_info info;

  info.candidates = candidates;
  info.num_candidates = num_viable_candidates;
  info.num_viable_candidates = num_viable_candidates;

  int counts[num_viable_candidates];
  // initialize to an invalid value
  for (unsigned int i = 0; i < num_viable_candidates; i++) {
    counts[i] = -1000;
  }
  info.counts = counts;

  info.ballots = read_ballots_from_file(ballots_filename, &info.num_ballots);
  cr_assert(info.ballots != NULL);
  // Initialize to an invalid value;
  info.exhausted_ballots = -1000;

  int actual_winner = run_round(&info);

  cr_assert_eq(expected_winner, actual_winner);
  cr_assert_eq(expected.num_viable_candidates, info.num_viable_candidates);
  cr_assert_eq(expected.exhausted_ballots, info.exhausted_ballots);

  // Verify the candiates and the counts
  for (unsigned int i = 0; i < expected.num_viable_candidates; i++) {
    cr_assert(strcmp(expected.candidates[i], info.candidates[i]) == 0);
    cr_assert_eq(expected.counts[i], info.counts[i]);
  }
}

Test(run_round, test0) {
  // Test from the writeup: has winner
  char *candidates[] = {"orange", "maroon", "red"};
  int num_viable_candidates = sizeof(candidates) / sizeof(char *);
  int expected_counts[] = {1, 0, 3};
  int expected_winner = 2;

  struct election_info expected_info;
  expected_info.exhausted_ballots = 1;
  expected_info.candidates = candidates;
  expected_info.num_viable_candidates = num_viable_candidates;
  expected_info.counts = expected_counts;

  do_rr_test("tests/ballots_0.txt", candidates, num_viable_candidates,
             expected_info, expected_winner);
}

Test(run_round, test1) {
  // Test from the writeup: no winner
  char *candidates[] = {"yellow", "blue", "red"};
  int num_viable_candidates = sizeof(candidates) / sizeof(char *);
  // Third candidate--"yellow"--gets dropped."
  char *expected_candidates[] = {"red", "blue", "yellow"};
  int expected_counts[] = {2, 2, 1};
  int expected_winner = -1;

  struct election_info expected_info;
  expected_info.exhausted_ballots = 0;
  expected_info.candidates = expected_candidates;
  expected_info.num_candidates = num_viable_candidates;
  expected_info.num_viable_candidates = num_viable_candidates;

  expected_info.counts = expected_counts;

  do_rr_test("tests/ballots_0.txt", candidates, num_viable_candidates,
             expected_info, expected_winner);
}

// ADD YOUR Task 7 tests here.
