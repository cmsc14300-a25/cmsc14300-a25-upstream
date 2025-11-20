/*
 * CMSC 14300
 * Autumn 2025
 * Homework #8: Election header file
 *
 * Do not modify this file
 */


#ifndef ELECTION_H
#define ELECTION_H

#include "record_election_results.h"

/* run_election: runs an election and returns the results for the
 *   rounds of the election.
 * voter_filename: the name of the voter file
 * candidate_filename: the name of the file with initial set of
 *   viable candidates
 *
 * Returns: a record of the results for all the rounds or NULL, if one
 *   or both of the files did not exist or were invalid.
 */
election_results_t *run_election(char *voter_filename, char *candidate_filename);

#endif
