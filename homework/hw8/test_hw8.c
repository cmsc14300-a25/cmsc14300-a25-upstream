#include <criterion/criterion.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "ballot.h"
#include "candidates.h"
#include "precinct.h"
#include "growable_array.h"
#include "election.h"
#include "record_election_results.h"

/****** Candidate tests ********/

Test(candidates, read_test0) {
  candidates_t *cands = read_candidates_from_file( "sample_files/candidates_0.txt");
  cr_assert(cands != NULL);

  cr_assert(cands->num_candidates == 3);
  cr_assert(strcmp(cands->names[0], "red") == 0);
  cr_assert(strcmp(cands->names[1], "blue") == 0);  
  cr_assert(strcmp(cands->names[2], "yellow") == 0);  

  free_candidates(cands);
}

Test(candidates, read_test1) {
  candidates_t *cands = read_candidates_from_file( "sample_files/some_random_filename.txt");
  cr_assert(cands == NULL);
}

Test(candidates, find_idx_test0) {
  candidates_t *cands = read_candidates_from_file( "sample_files/candidates_0.txt");
  cr_assert(cands != NULL);

  char *test[] = {"blue", "red", "green", "purple", "yellow"};
  int expected_idx[] = {1, 0, -1, -1, 2};

  for (unsigned int i = 0; i < sizeof(test)/sizeof(char *); i++) {
    int actual = find_candidate_idx(cands, test[i]);
    cr_assert_eq(actual, expected_idx[i]);
  }

  free_candidates(cands);
}

Test(candidates, drop_test0) {
  char *filename = "sample_files/candidates_0.txt";
  candidates_t *cands = read_candidates_from_file(filename);
  if (cands == NULL) {
    // read function will generate an error message.
    exit(1);
  }

  // drop yellow
  candidates_t *result1 = drop_candidate_by_idx(cands, 2);
  cr_assert(result1->num_candidates == 2);
  cr_assert(strcmp(result1->names[0], "red") == 0);
  cr_assert(strcmp(result1->names[1], "blue") == 0);  
  free_candidates(cands);  


  // drop red
  candidates_t *result2 = drop_candidate_by_idx(result1, 0);
  cr_assert(result2->num_candidates == 1);
  cr_assert(strcmp(result2->names[0], "blue") == 0);
  free_candidates(result1);  

  // drop blue
  candidates_t *result3 = drop_candidate_by_idx(result2, 0);
  cr_assert(result3->num_candidates == 0);
  free_candidates(result2);
  free_candidates(result3);    
}


/****** Ballot tests ********/

Test(ballot, ffvc_test0) {
  char *ballot[] = {"red", "yellow", "", "", ""};
  candidates_t *cands = read_candidates_from_file("sample_files/candidates_0.txt");

  int idx = find_first_viable_candidate(ballot, cands);
  cr_assert_eq(idx, 0);
}

Test(ballot, ffvc_test1) {
  char *ballot[] = {"magenta", "", "purple", "green", "blue"};
  candidates_t *cands = read_candidates_from_file("sample_files/candidates_0.txt");

  int idx = find_first_viable_candidate(ballot, cands);
  cr_assert_eq(idx, 1);
}

Test(ballot, ffvc_test2) {
  char *ballot[] = {"magenta", "", "purple", "green", ""};
  candidates_t *cands = read_candidates_from_file("sample_files/candidates_0.txt");

  int idx = find_first_viable_candidate(ballot, cands);
  cr_assert_eq(idx, -1);
}


Test(precinct, count_votes_test0) {
  char *name = "hyde-park-0";
  precinct_t *polling_place = mk_precinct(name);
  cr_assert(polling_place != NULL);

  // modify this array to check different cases...
  char *b0[] = {"red", "blue", "yellow", "", ""};
  char *b1[] = {"magenta", "", "purple", "green", "blue"};
  char *b2[] = {"magenta", "", "purple", "green", ""};
  ballot_t ballots[3] = {b0, b1, b2};

  unsigned int num_ballots = sizeof(ballots)/sizeof(*ballots);
  for (unsigned int i = 0; i < num_ballots; i++) {
    // make a copy to avoid sending a string literal to str_to_ballot
    add_ballot_to_precinct(polling_place, (char **) ballots[i]);
  }

  candidates_t *cands = read_candidates_from_file("sample_files/candidates_0.txt");
  if (cands == NULL) {
    // read function will generate an error message.
    return;
  }

  unsigned int num_exhausted_ballots;
  unsigned int *counts = count_votes_precinct(polling_place, cands, &num_exhausted_ballots);

  cr_assert(num_exhausted_ballots == 1);

  int expected_counts[] = {1, 1, 0};
  for (unsigned int i=0; i < cands->num_candidates; i++) {
    cr_assert(counts[i] == expected_counts[i]);
  }
  free(counts);
  free_candidates(cands);
}


/* Structure for storing the results of a single round */
struct round_results_copy {
  unsigned int round_num;
  int winner_idx;
  int dropped_idx;
  unsigned int num_available_votes;
  unsigned int num_exhausted_ballots;
  candidates_t *candidates;
  unsigned int *counts;
};


Test(election, test0) {
  election_results_t *results = run_election("sample_files/voter_file_1.csv", "sample_files/candidates_1.txt");
  cr_assert(results != NULL);

  cr_assert(garray_get_length(results) == 6);

  // round 1
  struct round_results_copy *r1 = (struct round_results_copy *) garray_get_val(results, 0);
  cr_assert(r1->num_available_votes == 6);
  cr_assert(r1->num_exhausted_ballots == 1);
  cr_assert(r1->winner_idx == -1);
  cr_assert(r1->dropped_idx == 5);
  
  struct round_results_copy *r2 = (struct round_results_copy *) garray_get_val(results, 1);
  cr_assert(r2->num_available_votes == 6);
  cr_assert(r2->num_exhausted_ballots == 1);
  cr_assert(r2->winner_idx == -1);
  cr_assert(r2->dropped_idx == 4);  
  
  struct round_results_copy *r3 = (struct round_results_copy *) garray_get_val(results, 2);
  cr_assert(r3->num_available_votes == 6);
  cr_assert(r3->num_exhausted_ballots == 1);
  cr_assert(r3->winner_idx == -1);
  cr_assert(r3->dropped_idx == 3);  

  struct round_results_copy *r4 = (struct round_results_copy *) garray_get_val(results, 3);
  cr_assert(r4->num_available_votes == 6);
  cr_assert(r4->num_exhausted_ballots == 1);
  cr_assert(r4->winner_idx == -1);
  cr_assert(r4->dropped_idx == 2);  

  struct round_results_copy *r5 = (struct round_results_copy *) garray_get_val(results, 4);
  cr_assert(r5->num_available_votes == 6);
  cr_assert(r5->num_exhausted_ballots == 1);
  cr_assert(r5->winner_idx == -1);
  cr_assert(r5->dropped_idx == 1);  

  struct round_results_copy *r6 = (struct round_results_copy *) garray_get_val(results, 5);
  cr_assert(r6->num_available_votes == 5);
  cr_assert(r6->num_exhausted_ballots == 2);
  cr_assert(r6->winner_idx == 0);
  cr_assert(r6->dropped_idx == -1);  
}
