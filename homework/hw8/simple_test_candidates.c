#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "candidates.h"

void test_drop() {
  char *filename = "sample_files/candidates_0.txt";
  candidates_t *cands = read_candidates_from_file(filename);
  if (cands == NULL) {
    // read function will generate an error message.
    exit(1);
  }

  unsigned int to_drop[] = {2, 0, 0};
  int num_to_drop = sizeof(to_drop)/sizeof(*to_drop);
  
  printf("\nTesting drop with initial candidates: ");
  print_candidates(cands);
  for (unsigned int i = 0; i < num_to_drop; i++) {
    unsigned int idx = to_drop[i];
    candidates_t *result = drop_candidate_by_idx(cands, idx);
    if (result == NULL) {
      fprintf(stderr, "drop_candidate_by_idx with index %d returned NULL", idx);
      exit(1);
    }
    free_candidates(cands);
    printf("Candidates after dropping candidate at index %d: ", idx);
    print_candidates(result);
    cands = result;
  }

  free_candidates(cands);
}

int main(int argc, char *argv[]) {
  char *filename;
  if (argc == 1) {
    filename = "sample_files/candidates_0.txt";
  } else {
    filename = argv[1];
  }

  candidates_t *cands = read_candidates_from_file(filename);
  if (cands == NULL) {
    // read function will generate an error message.
    exit(1);
  }

  print_candidates(cands);

  char *test[] = {"blue", "red", "green", "purple", "yellow"};

  for (unsigned int i = 0; i < 5; i++) {
    printf("%s: %d\n", test[i], find_candidate_idx(cands, test[i]));
  }

  free_candidates(cands);

  test_drop();

  
}
