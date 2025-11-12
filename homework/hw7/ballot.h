/*
 * CMSC 14300
 * Autumn 2025
 * Homework #7: Ballot header file
 *
 * Do not modify this file
 */

#ifndef BALLOT_H
#define BALLOT_H

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



#endif  // BALLOT_H
