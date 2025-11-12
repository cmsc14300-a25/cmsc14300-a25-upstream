/*
 * CMSC 14300
 * Autumn 2025
 * Homework #7: Precinct implementation
 *
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "growable_array.h"
#include "ballot.h"
#include "precinct.h"

struct precinct {
  char *name;
  garray_t *ballots;
};

#define INIT_SIZE 5

/* mk_precinct -- see precint.h for the header comment */
precinct_t *mk_precinct(char *name) {
  // TODO: complete this file.  Replace NULL with an appropriate
  // return value
  return NULL;
}


/* free_precinct -- see precint.h for the header comment */
void free_precinct(precinct_t *precinct) {
  assert(precinct != NULL);
  // TODO: complete this file
}


/* get_name_precinct -- see precinct.h for the header comment */
char *get_name_precinct(precinct_t *precinct) {
  assert(precinct != NULL);

  // TODO: complete this file and replace NULL with an appropriate
  // return value.
  return NULL;

}


/* add_ballot_to_precinct -- see precint.h for the header comment */
void add_ballot_to_precinct(precinct_t *precinct, ballot_t ballot) {
  assert(precinct != NULL);

  // TODO: complete this function.
}

/* dump_votes_to_file -- see precinct.h for the header comment */
void dump_votes_to_file(precinct_t *precinct, char *filename) {
  assert(precinct != NULL);
  assert(filename != NULL);

  // TODO: complete this function.
}



  
