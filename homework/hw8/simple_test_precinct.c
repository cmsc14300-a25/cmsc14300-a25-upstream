/*
 * CMSC 14300
 * Autumn 2025
 * Homework #7: precinct test code
 *
 */

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "ballot.h"
#include "precinct.h"


void test_count_votes(precinct_t *precinct, char *candidates_filename) {
  candidates_t *cands = read_candidates_from_file(candidates_filename);
  if (cands == NULL) {
    // read function will generate an error message.
    return;
  }

  printf("Using candidates: ");
  print_candidates(cands);
  printf("\n");

  unsigned int num_exhausted_ballots;
  unsigned int *counts = count_votes_precinct(precinct, cands, &num_exhausted_ballots);
  printf("Number of Exhausted ballots: %u\n", num_exhausted_ballots);
  printf("Vote Counts:\n");
  for (unsigned int i=0; i < cands->num_candidates; i++) {
    printf("    Slot %u - %s : %u\n", i, cands->names[i], counts[i]);
  }

  free(counts);
  free_candidates(cands);

}


int main(int argc, char *argv[]) {
  char *candidates_filename;
  if (argc != 2) {
    candidates_filename = "sample_files/candidates_0.txt";
  } else {
    candidates_filename = argv[1];
  }


  char *name = "hyde-park-0";
  precinct_t *polling_place = mk_precinct(name);
  if (polling_place == NULL) {
    fprintf(stderr, "It appears that mk_precinct has not been implemented\n");
    exit(1);
  }

  char *extracted_name = get_name_precinct(polling_place);
  if (extracted_name == NULL) {
    fprintf(stderr, "It that get_name_precinct has not been implemented\n");
    free_precinct(polling_place);
    exit(1);
  }


  assert(strcmp(extracted_name, name) == 0);

  // modify this array to check different cases...
  char *ballot_strs[] = {"red,blue,yellow,,",
			 "magenta,,purple,green,blue",
			 "magenta,,purple,green"
			 // add your test cases here.
  };


  unsigned int num_ballots = sizeof(ballot_strs)/sizeof(*ballot_strs);
  for (unsigned int i = 0; i < num_ballots; i++) {
    // make a copy to avoid sending a string literal to str_to_ballot
    char *str = strdup(ballot_strs[i]);
    add_ballot_to_precinct(polling_place, str_to_ballot(str));
    free(str);
  }

  dump_votes_to_file(polling_place, "./hyde-park-0.csv");

  // NEW in HW #8
  test_count_votes(polling_place, candidates_filename);

  free_precinct(polling_place);
}
