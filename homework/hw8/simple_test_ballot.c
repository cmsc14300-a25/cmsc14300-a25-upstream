/*
 * CMSC 14300
 * Autumn 2025
 * Homework #7: program for testing ballot_to_str.
 *
 */

#include <stdio.h>
#include <string.h>
#include<stdlib.h>

#include "ballot.h"
#include "candidates.h"

int main() {
  char *test_strs[] = {"red,blue,yellow,,",
		       "magenta,,purple,green,blue",
		       "magenta,,purple,green"
                       // add your test cases here.
                      };
  unsigned int num_tests = sizeof(test_strs)/sizeof(*test_strs);

  candidates_t *cands = read_candidates_from_file("sample_files/candidates_0.txt");
  if (cands == NULL) {
    fprintf(stderr, "could not find candidates file\n");
    return 1;
  }
  printf("Candidates: ");
  print_candidates(cands);
  printf("\n");
  
  for (unsigned int i = 0; i < num_tests; i++) {
    char *str = test_strs[i];

    // construct a ballot
    ballot_t b = str_to_ballot(str);

    if (b == NULL) {
      fprintf(stderr, "str_to_ballot returned NULL\n");
      continue;
    }
    // convert the ballot back to a string.  The result
    // should have four commas, even if the input did not.
    char *ballot_str = ballot_to_str(b);

    // print the result to check by hand
    printf("ballot :%s: => :%s:\n", test_strs[i], ballot_str);

    // check viable candidates...
    int idx = find_first_viable_candidate(b, cands);
    if (idx < 0) {
      printf("No viable candidates\n\n");
    } else {
      printf("First viable candidate %s at (candidate) index: %d)\n\n", cands->names[idx], idx);
    }

    // free all the space that was allocated for the test
    free_ballot(b);
    free(ballot_str);
  }
}
