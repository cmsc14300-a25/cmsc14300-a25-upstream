/*
 * CMSC 14300
 * Autumn 2025
 * Homework #3: Simple program to allocate and deallocate ballots
 *
 * Do not modify this file
 */

#include "stdio.h"
#include "stdlib.h"
#include "util.h"

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "usage: ./check_space <ballot file name>\n");
    exit(1);
  }

  int num_ballots;
  char ***ballots = read_ballots_from_file(argv[1], &num_ballots);
  if (ballots == NULL) {
    // read_ballots_from_file generates an error message
    exit(2);
  }
  free_ballots(ballots, num_ballots);
}
