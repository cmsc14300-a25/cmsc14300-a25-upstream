#include "util.h"

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ballot.h"

#define MAX_LINE_LEN 1000

/** Helper functions **/
/* ck_malloc: allocate s bytes of space and return a pointer to it.
 *   An error message will be printed and the program will exit
 *   if malloc fails.
 *
 * num_bytes: the number of bytes to allocate
 * fn_name: the name of the function making the call
 *
 * Returns: pointer to the space allocated
 */
void *ck_malloc(unsigned long s, char *fn_name) {
  void *tmp = malloc(s);
  if (tmp == NULL) {
    fprintf(stderr, "%s: ran out of space\n", fn_name);
    exit(1);
  }
  return tmp;
}

/* parse_ballot: construct a ballot, given a comma-separated string of up
 *  to NUM_SLOTS candidate names.
 *
 * line: a comma-separated list of candidate names
 *
 * Returns: a NUM_SLOTS length array of candidate names, represented as
 *   strings.
 */
char **parse_ballot(char *line) {
  char **result =
      (char **)ck_malloc(sizeof(char *) * NUM_CHOICES, "parse_ballot");
  char *start = line;
  for (unsigned int i = 0; i < NUM_CHOICES; i++) {
    char *candidate = strsep(&start, ",");
    /* Copy the name to allow reuse of line and to simplify deallocation. */
    if ((candidate == NULL) || (candidate[0] == '\0')) {
      result[i] = strdup(UNUSED_SLOT);
    } else {
      result[i] = strdup(candidate);
    }
  }
  return result;
}

/* API functions */
char ***read_ballots_from_file(char *filename, int *num_ballots) {
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    fprintf(stderr, "Could not open: %s\n", filename);
    return NULL;
  }

  // The first line of the file contains the number of ballots
  if (fscanf(fp, "%d\n", num_ballots) != 1) {
    fprintf(stderr,
            "Bad format first line should contain the number of ballots: %s\n",
            filename);
    return NULL;
  }

  char ***results = (char ***)ck_malloc(sizeof(char **) * *num_ballots,
                                        "read_ballots_from_file");
  size_t line_len = MAX_LINE_LEN;
  char *line =
      (char *)ck_malloc(sizeof(char) * line_len, "read_ballots_from_file");
  for (unsigned int i = 0; i < *num_ballots; i++) {
    int nc = getline(&line, &line_len, fp);
    if (nc == 0) {
      fprintf(stderr, "getline failed in read_ballots_from file\n");
      return NULL;
    }
    if (line[nc - 1] == '\n') {
      // remove the new line, if necessary
      line[nc - 1] = '\0';
    }
    results[i] = parse_ballot(line);
  }

  free(line);
  fclose(fp);

  return results;
}

void print_ballots(char **ballots[], int num_ballots) {
  assert(ballots != NULL);
  assert(num_ballots >= 0);
  printf("%d\n", num_ballots);
  for (unsigned int i = 0; i < num_ballots; i++) {
    char *b_str = ballot_to_str(ballots[i]);
    printf("%s\n", b_str);
    free(b_str);
  }
}

void free_ballots(char **ballots[], int num_ballots) {
  assert(ballots != NULL);
  assert(num_ballots >= 0);
  for (unsigned int i = 0; i < num_ballots; i++) {
    free_ballot(ballots[i]);
  }
  free(ballots);
}

char **read_candidates_from_file(char *filename, int *num_candidates) {
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    fprintf(stderr, "Could not open: %s\n", filename);
    return NULL;
  }

  // The first line of the file contains the number of ballots
  if (fscanf(fp, "%d\n", num_candidates) != 1) {
    fprintf(stderr,
            "Bad format: the first line should contain the number of "
            "candidates: %s\n",
            filename);
    return NULL;
  }

  char **results = (char **)ck_malloc(sizeof(char *) * *num_candidates,
                                      "read_candidates_from_file");
  size_t line_len = MAX_LINE_LEN;
  char *line = (char *)malloc(sizeof(char) * line_len);
  if (line == NULL) {
    fprintf(stderr, "read_candidate_from_file: ran out of space\n");
    exit(1);
  }
  for (unsigned int i = 0; i < *num_candidates; i++) {
    int nc = getline(&line, &line_len, fp);
    if (nc == 0) {
      // treat an empty line an error
      fprintf(stderr, "getline failed in read_candidates_from file\n");
      return NULL;
    }
    if (line[nc - 1] == '\n') {
      // remove the new line, if
      // necessary
      line[nc - 1] = '\0';
    }
    results[i] = strdup(line);
  }

  fclose(fp);
  free(line);
  return results;
}

void free_candidates(char *viable_candidates[], int num_candidates) {
  for (unsigned int i = 0; i < num_candidates; i++) {
    free(viable_candidates[i]);
  }
  free(viable_candidates);
}
