/*
 * CMSC 14300
 * Autumn 2025
 * Lab #4: Simple program for checking 2D matrix print and free functions
 *
 * Do not modify this file
 */

#include <stdio.h>
#include <string.h>

#include "matrix.h"

int main(int argc, char **argv) {
  struct matrix_2D_int *m;
  char *usage_msg = "Usage: ./print_test [matrix filename]";
  if (argc == 1) {
    // use a 3x4 matrix of all zeros as the default value
    m = make_matrix(3, 4);
  } else if (argc == 2) {
    if ((strcmp(argv[1], "--help") == 0) || (strcmp(argv[1], "-h") == 0)) {
      fprintf(stderr, "%s\n", usage_msg);
      exit(1);
    } else {
      m = read_matrix_from_file(argv[1]);
      if (m == NULL) {
        exit(2);
      }
    }
  } else {
    fprintf(stderr, "Too many arguments\n");
    fprintf(stderr, "%s\n", usage_msg);
    exit(3);
  }
  print_matrix(m);
  free_matrix(m);
}
