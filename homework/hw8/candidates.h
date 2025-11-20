/*
 * CMSC 14300
 * Autumn 2025
 * Homework #8: Candidate header file
 *
 * Do not modify this file
 */

#ifndef CANDIDATE_H
#define CANDIDATE_H

/**** This header file is NEW in Homework 8 ****/

// This data structure is public and can be used by clients.
typedef struct candidates {
  unsigned int num_candidates;
  char **names;
} candidates_t;


/* read_candidates_from_file: function that reads the
 *   a set of candidates from a file
 *
 * filename: the name of the candidate file
 *
 * Returns: a data structure representing the
 *   candidates from the file.
 */
candidates_t *read_candidates_from_file(char *filename);


/* 
 * free_candidates: free the space associated with a set of
 *   candidates.
 *
 * candidates: the candidates
 *
 * Returns: nothing
 */
void free_candidates(candidates_t *candidates);


/* print_candidates: print the candidates
 *
 * candidates: the candidates of interest
 *
 * Returns: nothing.
 */ 
void print_candidates(candidates_t *candidates);


/* find_candidate_idx: find the index of the specified candidate
 *
 * candidates: the candidates of interest
 * name: the name of the candidate to find
 *
 * Returns: the index of the candidate in the candidate array
 *   or -1, if the specified name is not valid candidate name
 */
int find_candidate_idx(candidates_t *candidates, char *cand);


/* drop_candidate_by_idx: construct a new candidates structure
 *   that contains all the candidates except the one at the
 *   specified index.
 *
 * candidates: the candidates of interest
 * idx: the index of the candidate in the array (must be a valid index)
 *
 * Returns: a pointer to a new candidates structure
 */ 
candidates_t *drop_candidate_by_idx(candidates_t *candidates, unsigned int idx);

#endif
