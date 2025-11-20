/*
 * CMSC 14300
 * Autumn 2025
 * Homework #8: utility function header file
 *
 * Do not modify this file
 */

#ifndef UTIL_H
#define UTIL_H

/* trim_trailing_white_space_in_place: trim space, tabs, newlines, etc from line
 *
 * line: the string to trim
 * nc: the number of characters in the string
 *
 * Returns: the number of characters in the trimmed string.
 */
unsigned int trim_trailing_white_space_in_place(char *line, int nc);

#endif
