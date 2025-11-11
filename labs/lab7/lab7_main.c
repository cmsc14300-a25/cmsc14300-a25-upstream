/*
 * CMSC 14300
 * Autumn 2025
 * Lab #7: I/O and Simple String Parsing: main file
 *
 * You will not modify this file as part of the lab.
 */


#include <stdio.h>
#include <stdlib.h>

#include "growable_array.h"
#include "lab7.h"

int main() {
  // read the data
  garray_t *ballots = read_voter_file("voter_file_0.csv");
  if (ballots == NULL) {
    return 1;
  }

  // write the data
  split_and_dump(ballots, "voter_file_0_chunks");

  // clean up.
  free_ballot_garray(ballots);
}  
