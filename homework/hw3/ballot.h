/*
 * CMSC 14300
 * Autumn 2025
 * Homework #3: Ballot header file
 *
 * Do not modify this file
 */

#ifndef BALLOT_H
#define BALLOT_H

#define NUM_CHOICES 5
#define UNUSED_SLOT ""

/* find_index_first_viable: find the index in the viable candidates array
 *   voter's first viable choice.
 *
 * viable_canidates: the viable candidates
 * num_candidates: the number of viable candidates
 * ballot: a voter's ranked choice ballot
 *
 * Returns: the index (in the viable candidates array) the voter's first
 *   viable choice.  -1 if none of the candidates in the ballot are viable.
 */
int find_index_first_viable(char *viable_candidate[], int num_candidates,
                            char *ballot[]);

/* ballot_to_str: constructs a comma separated string with candidates
 *   in the voter's ballot.
 *
 *  ballot: a voter's ranked choice ballot
 *
 * Returns: a string with the names of the candidates in the ballot
 *   separated by commas.
 */
char *ballot_to_str(char *ballot[]);

/* free_ballot: free the space associated with a ballot
 *
 *  ballot: a voter's ranked choice ballot
 */
void free_ballot(char *ballot[]);

#endif  // BALLOT_H