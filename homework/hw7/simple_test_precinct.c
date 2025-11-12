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


int main() {
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
  char *ballot_strs[] = {"aaa,bbb,ccc,ddd,eee",
                         "fff,ggg,hhh,iii,jjj",
                         "k,l,m,n,o"};

  unsigned int num_ballots = sizeof(ballot_strs)/sizeof(*ballot_strs);
  for (unsigned int i = 0; i < num_ballots; i++) {
    // make a copy to avoid sending a string literal to str_to_ballot
    char *str = strdup(ballot_strs[i]);
    add_ballot_to_precinct(polling_place, str_to_ballot(str));
    free(str);
  }

  dump_votes_to_file(polling_place, "./hyde-park-0.csv");

  free_precinct(polling_place);
}
