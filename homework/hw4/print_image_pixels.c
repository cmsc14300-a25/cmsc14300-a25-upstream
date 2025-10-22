#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "image.h"
#include "util.h"

int main(int argc, char **argv) {
  struct image *img;
  char *usage_msg = "Usage: ./print_image_pixels [ppm filename]";
  if (argc == 1) {
    // use a 3x4 all-black img as the default value
    img = create_blk_image(3, 4);
  } else if (argc == 2) {
    if ((strcmp(argv[1], "--help") == 0) || (strcmp(argv[1], "-h") == 0)) {
      fprintf(stderr, "%s\n", usage_msg);
      exit(1);
    } else {
      img = read_image(argv[1]);
      if (img == NULL) {
        exit(2);
      }
    }
  } else {
    fprintf(stderr, "Too many arguments\n");
    fprintf(stderr, "%s\n", usage_msg);
    exit(3);
  }

  print_image(img);
  free_image(img);
}