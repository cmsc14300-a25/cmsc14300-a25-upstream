#include <assert.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "candidates.h"
#include "util.h"


/********** Helpers **********/

// YOUR HELPER FUNCTIONS GO HERE...


/********** API functions **********/

/* read_candidates_from_file -- see candidates.h for the header comment */
candidates_t *read_candidates_from_file(char *filename) {
  assert(filename != NULL);
  
  // TODO: complete this function
  // Replace NULL with an appropriate return value
  return NULL;
}


/* free_candidates -- see candidates.h for the header comment */
void free_candidates(candidates_t *candidates) { 
  // TODO: complete this function
}


/* print_candidates -- see candidates.h for the header comment */
void print_candidates(candidates_t *candidates) {
  assert(candidates != NULL);
  
  // OPTIONAL: complete this function
}


/* find_candidate_index -- see candidates.h for the header comment */
int find_candidate_idx(candidates_t *candidates, char *cand) {
  assert(candidates != NULL);
  assert(cand != NULL);
  
  // TODO: complete this function
  // Replace -1 with an appropriate return value
  return -1;
}


/* drop_candidate_by_idx -- see candidates.h for the header comment */
candidates_t *drop_candidate_by_idx(candidates_t *candidates, unsigned int idx) {
  assert(candidates != NULL);
  assert(idx < candidates->num_candidates);

  // TODO: complete this function
  // Replace NULL with an appropriate return value
  return NULL;
}

