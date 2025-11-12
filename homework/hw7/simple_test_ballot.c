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

int main() {
  char *test_strs[] = {"aaa,bbb,ccc,ddd,eee",
		       "aaa,,fff,ddd,eee"
                       // add your test cases here.
                      };
  unsigned int num_tests = sizeof(test_strs)/sizeof(*test_strs);

  for (unsigned int i = 0; i < num_tests; i++) {
    // duplicate the test string to allow it to be modified.
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
    printf(":%s: => :%s:\n", test_strs[i], ballot_str);

    // free all the space that was allocated for the test
    free_ballot(b);
    free(ballot_str);
  }
}
