#ifndef UTIL_H
#define UTIL_H
/*** DO NOT CHANGE THIS FILE ***/

#include "image.h"

/* read_image: read a image from a file
 *
 * filename: name of file
 *
 * Returns: a pointer to an image struct or NULL, if the file does not exist or is not
 *  for matted properly.
 */
struct image *read_image(char *filename);

/* write_image: write a image struct to a file
 *
 * filename: name of file
 * image: image to write to file
 *
 */
void write_image(char *filename, struct image *image);

#endif
