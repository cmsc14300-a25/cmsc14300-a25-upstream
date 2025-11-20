/*
 * CMSC 14300
 * Autumn 2025
 * Homework #8: Ballot header file
 *
 * Do not modify this file
 */

#ifndef BALLOT_H
#define BALLOT_H

#include "candidates.h"

typedef char **ballot_t;

/* str_to_ballot: construct a ballot from a string with the voter's
 *   choices in order and separated commas.
 *
 * str: a string of candidate names, separated by commas.
 *
 * Returns: a ballot constructed from the string
 */
ballot_t str_to_ballot(char *str);


/* ballot_to_str: constructs a comma separated string with candidates
 *   in the voter's ballot.
 *
 *  ballot: a voter's ranked choice ballot
 *
 * Returns: a string with the names of the candidates in the ballot
 *   separated by commas.
 */
char *ballot_to_str(ballot_t ballot);


/* free_ballot: free the space associated with a ballot
 *
 *  ballot: a voter's ranked choice ballot
 */
void free_ballot(ballot_t ballot);

/**** NEW in Homework 8 ****/

/* find_index_first_viable: find the index (in the viable candidates
 *   data structure) of voter's first viable choice.
 *
 * ballot: a voter's ranked choice ballot
 * viable_canidates: the viable candidates

 *
 * Returns: the index the voter's first viable choice.  -1 if none of
 *   the candidates in the ballot are viable.
 */
int find_first_viable_candidate(ballot_t ballot, candidates_t *viable_candidates);



#endif  // BALLOT_H
