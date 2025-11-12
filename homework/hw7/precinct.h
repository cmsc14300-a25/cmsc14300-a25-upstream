/*
 * CMSC 14300
 * Autumn 2025
 * Homework #7: Precinct header file
 *
 */

#ifndef PRECINCT_H
#define PRECINCT_H

#include "ballot.h"

typedef struct precinct precinct_t;

/* mk_precinct: construct a precinct with the specified name and zero
 * votes, initially.
 *
 * name: the name of the precinct
 *
 * Returns: a precinct
 */
precinct_t *mk_precinct(char *name);


/* free_precinct: free the space associated with a precinct, including
 * the ballots.
 *
 * precinct: the precinct of interest
 *
 * Returns: nothing.
 */
void free_precinct(precinct_t *precinct);


/* get_name_precinct: returns the name of the precinct
 *
 * precinct: the precinct of interest
 *
 * Returns: the name of the precinct
 */
char *get_name_precinct(precinct_t *precinct);


/* add_ballot_to_precinct: add a ballot to the list of ballots for the precinct
 *
 * precinct: the precinct of interest
 * ballot: the ballot to add
 *
 * Returns: nothing
 */
void add_ballot_to_precinct(precinct_t *precinct, ballot_t ballot);


/* dump_votes_to_file: write the votes from a precinct out to the
 *   specified file.
 *
 * precinct: the precinct of interest
 * filename: the name of the output file
 *
 * Returns: nothing
 */
void dump_votes_to_file(precinct_t *precinct, char *filename);

#endif
