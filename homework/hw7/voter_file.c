/*
 * CMSC 14300
 * Autumn 2025
 * Homework #7: Program for converting voter files into per-precinct files.
 *
 * Do not modify this file
 */


#include <assert.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>

#include "ballot.h"
#include "precinct.h"
#include "precinct_map.h"

// Read/Write/Execute permissions for owner
#define DIR_PERMISSIONS 0700


/* Provided helper function */
/* trim_trailing_white_space_in_place: trim space, tabs, newlines, etc from line
 *
 * line: the string to trim
 * nc: the number of characters in the string
 *
 * Returns: the number of characters in the trimmed string.
 */
static int trim_trailing_white_space_in_place(char *line, int nc) {
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

/* read_voter_file: read precinct labelled votes from a voter file
 *   and construct a precinct map.
 *
 * filename: the name of the file
 *
 * Returns: a precinct map or NULL, if an error was encountered.
 */
precinct_map_t *read_voter_file(char *filename) {
  // TODO: complete this function
  // Replace NULL with an appropriate return value
  return NULL;
}


/* dump_by_precinct: constructs a directort, with one precinct file
 *   per precinct
 *
 * pm: a precinct map
 * directory_name: the name of the directory to use for the precinct files
 *
 * Returns: true, if the files were written successfully and false, if
 *   the function encountered an error.
 */
bool dump_by_precinct(precinct_map_t *pm, char *directory_name) {
  // TODO: complete this function
  // Replace NULL with an appropriate return value
  return false;
}


int main(int argc, char *argv[]) {
  // TODO: complete this function
}
