/*
 * CMSC 14300
 * Autumn 2025
 * Homework #7: Ballot implementation
 *
 */

#include "ballot.h"

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_CHOICES 5
#define UNUSED_SLOT ""

/* str_to_ballot -- see ballot.h for the header comment */
ballot_t str_to_ballot(char *str) {
  assert(str != NULL);
  // TODO complete this function and replace NULL with an appropriate
  // return value.
  return NULL;
}


/* ballot_to_str -- see ballot.h for the header comment */
char *ballot_to_str(ballot_t ballot) {
  assert(ballot != NULL);
  // Determine the length of the result.  Include space for
  // (NUM_CHOICE - 1) commas and the nul terminator.
  int result_len = NUM_CHOICES;
  for (unsigned int i = 0; i < NUM_CHOICES; i++) {
    if (strcmp(ballot[i], UNUSED_SLOT) != 0) {
      result_len += strlen(ballot[i]);
    }
  }

  // allocate space for the result
  char *result = (char *)calloc(sizeof(char), result_len);
  if (result == NULL) {
    fprintf(stderr, "ballot_to_str: ran out of space\n");
    exit(1);
  }

  // fill in the result
  for (unsigned int i = 0; i < NUM_CHOICES; i++) {
    // copy the voter's choice into the string.
    result = strncat(result, ballot[i], strlen(ballot[i]));
    if (i < NUM_CHOICES - 1) {
      result = strncat(result, ",", 1);
    }
  }
  return result;
}


/* free_ballot -- see ballot.h for the header comment */
void free_ballot(ballot_t ballot) {
  if (ballot != NULL) {
    for (unsigned int i = 0; i < NUM_CHOICES; i++) {
      // free the candidate strings
      free(ballot[i]);
    }
    free(ballot);
  }
}
