/*
 * CMSC 14300
 * Autumn 2025
 * Homework #1: C file
 *
 */

#include <stdio.h>
#include <stdlib.h>

#include "hw1.h"

int main(int argc, char **argv) {
  if (argc != 3) {
    fprintf(stderr, "usage: %s integer integer\n", argv[0]);
    exit(1);
  }

  int arg1 = atoi(argv[1]);
  int arg2 = atoi(argv[2]);
  printf("%d + %d = %d\n", arg1, arg2, add_two_nums(arg1, arg2));
}
