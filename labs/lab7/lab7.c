/*
 * CMSC 14300
 * Autumn 2025
 * Lab #7: I/O and Simple String Parsing.
 *
 * You will modify this file as part of the lab.
 */

#include <assert.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>

#include "lab7.h"
#include "growable_array.h"

#define NUM_CHOICES 5
#define UNUSED_SLOT ""

#define BALLOTS_PER_FILE 5

// Read/Write/Execute permissions for owner
#define DIR_PERMISSIONS 0700


typedef char **ballot_t;

/**** Provided helper functions ****/

/* trim_trailing_white_space_in_place: trim space, tabs, newlines, etc from line
 *
 * line: the string to trim
 * nc: the number of characters in the string
 *
 * Returns: the number of characters in the trimmed string.
 */
static int trim_trailing_white_space_in_place(char *line, int nc) {
  // trim trailing white space, in place.
  // find the index of the last non-whitespace character
  nc = nc - 1;
  while ((nc >= 0) && (isspace(line[nc]))) {
    nc--;
  }

  // place the nul terminator after the last
  // non-whitespace character.
  nc++;
  line[nc] = '\0';

  return nc;
}

/* free_ballot: free the space associated with a ballot
 *
 * ballot: the ballot to free
 *
 */
void free_ballot(ballot_t ballot) {
  for (unsigned int i = 0; i < NUM_CHOICES; i++) {
    free(ballot[i]);
  }
  free(ballot);
}


/* free_ballot_garray: free space for representing an array of ballots
 *
 * ballots: the ballots to free
 *
 * Returns: nothing
 */
void free_ballot_garray(garray_t *ballots) {
  unsigned int num_ballots = garray_get_length(ballots);
  for (unsigned int i = 0; i < num_ballots; i++) {
    ballot_t b = garray_get_val(ballots, i);
    free_ballot(b);
  }
  garray_free(ballots);
}


/* ballot_to_str: constructs a comma separated string with candidates
 *   in the voter's ballot.
 *
 *  ballot: a voter's ranked choice ballot
 *
 * Returns: a string with the names of the candidates in the ballot
 *   separated by commas.
 */
char *ballot_to_str(char *ballot[]) {
  // Compute the length of the result.
  // Start with (NUM_CHOICE - 1) commas plus 1 for the nul terminator.
  int result_len = NUM_CHOICES;
  for (unsigned int i = 0; i < NUM_CHOICES; i++) {
    if (strcmp(ballot[i], UNUSED_SLOT) != 0) {
      result_len += strlen(ballot[i]);
    }
  }

  // allocate space for the string
  char *result = (char *)calloc(sizeof(char), result_len);
  if (result == NULL) {
    fprintf(stderr, "ballot_to_str: ran out of space\n");
    exit(1);
  }

  char *next_spot = result;
  // fill it in.
  for (unsigned int i = 0; i < NUM_CHOICES; i++) {
    size_t blen = strlen(ballot[i]);
    // copy the voter's choice into the string.
    memcpy(next_spot, ballot[i], blen);
    next_spot += blen;

    if (i < NUM_CHOICES - 1) {
      *next_spot++  = ',';
    }
  }
  *next_spot++  = '\0';      
  return result;
}


/***** Tasks ******/
/***** Task 1 *****/
/* str_to_ballot: construct a ballot from a string with the voter's
 *   choices in order and separated commas.
 *
 * str: a string of candidate names, separated by commas.
 *
 * Returns: a ballot constructed from the string
 */
ballot_t str_to_ballot(char *str) {
  // TODO: complete this function
  // Replace NULL with a suitable return value
  return NULL;
}


/***** Task 2 *****/
/* read_voter_file: read precinct labelled votes from a voter file
 *   and construct a growable array of ballots
 *
 * filename: the name of the file
 *
 * Returns: a growable array of ballots
 */
garray_t *read_voter_file(char *filename) {
  // TODO: complete this function
  // Replace NULL with a suitable return value
  return NULL;
}  
    
    
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
void dump_chunk_to_file(garray_t *ballots, int lb, int ub, char *filename) {
  // TODO: complete this function
}



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
void split_and_dump(garray_t *ballots, char *directory_name) {
  // TODO: complete this function
}
