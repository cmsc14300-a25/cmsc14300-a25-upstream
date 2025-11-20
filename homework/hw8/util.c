/*
 * CMSC 14300
 * Autumn 2025
 * Homework #8: utility function implementation
 *
 * Do not modify this file
 */

#include <ctype.h>

#include "util.h"

/* trim_trailing_white_space_in_place - see util.h for the header comment */
unsigned int trim_trailing_white_space_in_place(char *line, int nc) {
  // trim trailing white space, in place.
  // find the index of the last non-whitespace character
  nc = nc - 1;
  while ((nc >= 0) && (isspace(line[nc]))) {
    nc--;
  }

  // place the nul terminator after the last
  // non-whitespace character.
  nc++;
  line[nc] = '\0';

  return nc;
}

