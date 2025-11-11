/*
 * CMSC 14300
 * Autumn 2025
 * Lab #7: I/O and Simple String Parsing: header file
 *
 * You will not modify this file as part of the lab.
 */

#ifndef LAB7_H
#define LAB7_H

#include "growable_array.h"

typedef char **ballot_t;

/** Provided functions **/
/* free_ballot: free the space associated with a ballot
 *
 * ballot: the ballot to free
 *
 */
void free_ballot(ballot_t ballot);


/* ballot_to_str: constructs a comma separated string with candidates
 *   in the voter's ballot.
 *
 *  ballot: a voter's ranked choice ballot
 *
 * Returns: a string with the names of the candidates in the ballot
 *   separated by commas.
 */
char *ballot_to_str(char *ballot[]);


/* free_ballot_garray: free space for representing an array of ballots
 *
 * ballots: the ballots to free
 *
 * Returns: nothing
 */
void free_ballot_garray(garray_t *ballots);


/***** Task 1 *****/
/* str_to_ballot: construct a ballot from a string with the voter's
 *   choices in order and separated commas.
 *
 * str: a string of candidate names, separated by commas.
 *
 * Returns: a ballot constructed from the string
 */
ballot_t str_to_ballot(char *str);

/***** Task 2 *****/
/* read_voter_file: read precinct labelled votes from a voter file
 *   and construct a growable array of ballots
 *
 * filename: the name of the file
 *
 * Returns: a growable array of ballots
 */
garray_t *read_voter_file(char *filename);
    
    
/***** Task 3 *****/
/* dump_chunk_to_file: write the votes from the specified range in
 *   the growable array out to a file.
 *
 * ballots: an array of ballots
 * lb: the lower bound of the range to store in the file (inclusive)
 * ub: the lower bound of the range to store in the file (non-inclusive)
 * filename: the name of the output file
 *
 * Returns: nothing
 */
void dump_chunk_to_file(garray_t *ballots, int lb, int ub, char *filename);


/***** Task 4 *****/
/* split_and_dump: (logically) splits the ballots into chunks and
 *   writes a chunk out to a file in the specified directory.
 *   The function creates the specified directory, is necessary.
 *
 * ballots: a growable array of ballots
 * directory_name: the name of the target directory
 *
 * Returns: nothing
 */
void split_and_dump(garray_t *ballots, char *directory_name);

#endif
