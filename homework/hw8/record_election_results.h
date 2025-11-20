/*
 * CMSC 14300
 * Autumn 2025
 * Homework #8: Record results header file
 *
 * Do not modify this file
 */


#ifndef RECORD_RESULTS_H
#define RECORD_RESULTS_H

#include <stdbool.h>

#include "candidates.h"
#include "growable_array.h"

// Type for representing the results for a single round
typedef struct round_results round_results_t;

// Type for representing results for an election
typedef garray_t election_results_t;



/* mk_election_results: construct an instance of election results
 *
 * Returns: a data structure for collecting per-round election results
 */
election_results_t *mk_election_results(void);


/* mk_round_results: construct record to store the results of a single
 *   round
 *
 * round_num: the round number
 * winner_idx: the index of the winner in the round or -1, if there was
 *   no winner
 * drop_idx: the index of the candidate to be dropped for the next round or
 *   -1, if a winner was identified.
 * num_available_votes: the number of ballots that had a viable candidate
 * num_exhausted_ballots: the number of ballots that did not have a viable candidate
 * candidates: the candidates used for the round
 * counts: the number of votes each candidate earned in the round.
 * 
 * Returns: a data structure for representing the results for a single round.
 */
round_results_t *mk_round_result(unsigned int round_num, int winner_idx, int drop_idx,
				 unsigned int num_available_votes, unsigned int num_exhausted_ballots,
				 candidates_t *candidates, unsigned int *counts);


/* free_election_results: free the space associated with the results,
 *   including each round's candidates and counts.
 *
 * results: the election results to free
 *
 * Returns: nothing
 */
void free_election_results(election_results_t *results);


/* add_result: add the results for a round to the results for an election
 *
 * election_results: the election results to update
 * round_results: the round results to add
 *
 * Returns: nothing
 */
void add_result(election_results_t *election_results, round_results_t *round_results);


/* print_results: print the results of an election
 *
 * results: the election results to update
 * final_only: print the results of last round only, if true, print
 *   all the rounds, if false.
 *
 * Returns: nothing
 */
void print_election_results(election_results_t *results, bool final_only);

#endif
