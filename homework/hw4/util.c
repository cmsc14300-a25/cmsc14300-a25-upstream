/*** DO NOT CHANGE THIS FILE ***/

#include "util.h"

#include <stdio.h>
#include <stdlib.h>

#include "image.h"

struct image *read_image(char *filename) {
  FILE *fp;
  int c, rgb_comp_color;
  char buff[16];

  // open image file for reading
  fp = fopen(filename, "r");
  if (!fp) {
    fprintf(stderr, "read_image: Unable to open file '%s'\n", filename);
    return NULL;
  }

  // read image format
  if (!fgets(buff, sizeof(buff), fp)) {
    perror(filename);
    return NULL;
  }

  // check the image format
  if (buff[0] != 'P' || buff[1] != '3') {
    fprintf(stderr, "read_image: Image format must be 'P3'\n");
    return NULL;

  }

  // check for comments
  c = getc(fp);
  while (c == '#') {
    while (getc(fp) != '\n') {
      // skip whitespace
    }
    c = getc(fp);
  }

  ungetc(c, fp);

  int width, height;
  // read image size information
  if (fscanf(fp, "%d %d", &width, &height) != 2) {
    fprintf(stderr, "read_image: Invalid image size (error loading '%s')\n",
            filename);
    return NULL;
  }

  // read rgb component
  if (fscanf(fp, "%d", &rgb_comp_color) != 1) {
    fprintf(stderr, "read_image: Invalid rgb component (error loading '%s')\n",
            filename);
    return NULL;
  }

  while (fgetc(fp) != '\n') {
    // skip whitespace
  }

  // memory allocation for pixel data
  struct image *image = create_blk_image(height, width);
  if (image == NULL) {
    fprintf(stderr, "read_image: cannot proceed because create_blk_image returned NULL\n");
    return NULL;
  }

  // read pixels
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      // %hhu specifies that the value that should
      // be read is an unsigned character.
      fscanf(fp, "%hhu", &(image->pixels[i][j].red));
      fscanf(fp, "%hhu", &(image->pixels[i][j].green));
      fscanf(fp, "%hhu", &(image->pixels[i][j].blue));
    }
  }

  fclose(fp);
  return image;
}


void write_image(char *filename, struct image *image) {
  FILE *fp;

  // open file for output
  fp = fopen(filename, "w");
  if (!fp) {
    fprintf(stderr, "write_image: Unable to open file '%s'\n", filename);
    exit(1);
  }

  // image format
  fprintf(fp, "P3\n");

  // image size
  fprintf(fp, "%d %d\n", image->width, image->height);

  // rgb component depth
  fprintf(fp, "%d\n", 255);

  // write rgb pixels
  for (int i = 0; i < image->height; i++) {
    for (int j = 0; j < image->width; j++) {
      fprintf(fp, "%d ", (image->pixels[i][j].red));
      fprintf(fp, "%d ", (image->pixels[i][j].green));
      fprintf(fp, "%d ", (image->pixels[i][j].blue));
    }
    fprintf(fp, "\n");
  }
  fclose(fp);
}
