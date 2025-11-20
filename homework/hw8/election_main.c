#include <assert.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <pthread.h>

#include "record_election_results.h"
#include "election.h"

/* parse_args: Construct the information needed to run a round.
 *
 * argc: the number of command-line arguments
 * argv: the command-line arguments
 *
 * Returns: true, if the arguments were successfully parsed and false,
 * otherwise.
 */
bool parse_args(int argc, char *argv[],
		char **ballots_filename,
		char **candidates_filename,
		bool *verbose) {
  int opt;
  char *usage = "Usage: %s -b ballot_filename -c candidate_filename [-h] [-v]\n";

  *ballots_filename = NULL;
  *candidates_filename = NULL;
  *verbose = false;

  // Parse the arguments: expect both a ballot filename
  // and a candidate filename
  while ((opt = getopt(argc, argv, "b:c:vh")) != -1) {
    switch (opt) {
      case 'b':
        if (*ballots_filename != NULL) {
          fprintf(stderr, "Error: Multiple ballot files supplied.\n");
          fprintf(stdout, usage, argv[0]);
          return false;
        }
        *ballots_filename = strdup(optarg);
        break;
      case 'c':
        if (*candidates_filename != NULL) {
          fprintf(stderr, "Error: Multiple candidates files supplied.\n");
          fprintf(stdout, usage, argv[0]);
          return false;
        }
        *candidates_filename = strdup(optarg);
        break;
      case 'v':
        *verbose = true;
        break;
      case 'h':
        fprintf(stdout, usage, argv[0]);
        return false;
      default:
        fprintf(stderr, usage, argv[0]);
        return false;
    }
  }

  if ((*ballots_filename == NULL) || (*candidates_filename == NULL)) {
    fprintf(stderr,
            "Error: missing one or both of the ballot and candidate file "
            "names.\n");
    fprintf(stderr, usage, argv[0]);

    // cleanup
    if (*ballots_filename != NULL) { free(*ballots_filename); }
    if (*candidates_filename != NULL) { free(*candidates_filename); }    
    return false;
  }

  return true;
}


int main(int argc, char *argv[]) {
  char *ballots_filename;
  char *candidates_filename;
  bool verbose;

  if (!parse_args(argc, argv, &ballots_filename, &candidates_filename, &verbose)) {
    // parse args will generate an error.
    exit(1);
  }

  election_results_t *election_results = run_election(ballots_filename, candidates_filename);
  if (election_results != NULL) {
    print_election_results(election_results, verbose);
    free_election_results(election_results);
  }

  free(ballots_filename);
  free(candidates_filename);
}
