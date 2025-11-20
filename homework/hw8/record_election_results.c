/*
 * CMSC 14300
 * Autumn 2025
 * Homework #8: Record results implementation
 *
 * Do not modify this file
 */

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "candidates.h"
#include "growable_array.h"
#include "record_election_results.h"


/* Structure for storing the results of a single round */
struct round_results {
  unsigned int round_num;
  int winner_idx;
  int dropped_idx;
  unsigned int num_available_votes;
  unsigned int num_exhausted_ballots;
  candidates_t *candidates;
  unsigned int *counts;
};

/*************** Helper functions ***************/
/* print_result: print the results for a single round
 *
 * result: the results to print
 *
 * Returns: nothing
 */
void print_round_result(round_results_t *result) {
  printf("Round %d: \n", result->round_num);
  printf("  Number of available votes: %d\n", result->num_available_votes);
  printf("  Number of exhausted ballots : %d\n", result->num_exhausted_ballots);
  printf("  Vote Counts:\n");
  for (unsigned int i=0; i < result->candidates->num_candidates; i++) {
    printf("    Slot %d - %s : %d\n", i, result->candidates->names[i], result->counts[i]);
  }
  printf("\n");
  if (result->winner_idx >= 0) {
    printf("  Winner: %s (slot: %d)\n", result->candidates->names[result->winner_idx], result->winner_idx);
  } else if (result->num_available_votes == 0) {
    printf("  All ballots exhausted\n");
  } else {
    printf("  Dropping: %s (slot: %d)\n", result->candidates->names[result->dropped_idx], result->dropped_idx);
  }
  printf("\n\n");
}


/*************** API functions ***************/

/* see record_election_results.h for the header comment */
election_results_t *mk_election_results(void) {
  garray_t *results = mk_garray(1);
  return results;
}

/* see record_election_results.h for the header comment */
round_results_t *mk_round_result(unsigned int round_num, int winner_idx, int dropped_idx,
				 unsigned int num_available_votes, unsigned int num_exhausted_ballots,
				 candidates_t *candidates, unsigned int *counts) {
  round_results_t *result = (round_results_t *) malloc(sizeof(*result));
  if (result == NULL) {
    fprintf(stderr, "add_result: out of space\n");
    exit(1);
  }

  result->round_num = round_num;
  result->winner_idx = winner_idx;
  result->dropped_idx = dropped_idx;
  result->num_available_votes = num_available_votes;
  result->num_exhausted_ballots = num_exhausted_ballots;
  result->candidates = candidates;
  result->counts = counts;

  return result;
}

/* see record_election_results.h for the header comment */
void free_election_results(election_results_t *results) {
  unsigned int result_len = garray_get_length(results);
  for (unsigned int i = 0; i < result_len; i++) {
    round_results_t *round_results = garray_get_val(results, i);
    free_candidates(round_results->candidates);
    free(round_results->counts);
    free(round_results);
  }
  garray_free(results);
}


/* see record_election_results.h for the header comment */
void add_result(election_results_t *results, round_results_t *round_result) {
  garray_append(results, round_result);
}


/* see record_election_results.h for the header comment */
void print_election_results(election_results_t *results, bool verbose) {
  assert(results != NULL);
  unsigned int result_len = garray_get_length(results);
  assert(result_len > 0);

  if (verbose) {
    for (unsigned int i = 0; i < result_len; i++) {
      round_results_t *round_results = garray_get_val(results, i); 
      print_round_result(round_results);
    }
  } else {
    print_round_result(garray_get_val(results, result_len - 1));
  }      
}
