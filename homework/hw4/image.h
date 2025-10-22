/*
 * CMSC 14300
 * Autumn 2025
 * Homework #4: Image header file
 *
 * Do NOT modify this file
 */

#ifndef IMAGE_H
#define IMAGE_H

#define MAX_INTENSITY 255

struct color {
  unsigned char red;
  unsigned char green;
  unsigned char blue;
};

struct image {
  int height;
  int width;
  struct color **pixels;
};

/* new_image: create new black image
 *
 * height: height of image
 * width: width of image
 *
 * Returns: a pointer to an image
 */
struct image *create_blk_image(int height, int width);

/* free_image: free an image
 *
 * input: pointer to the image to free
 */
void free_image(struct image *input);

/*
 * print_image: print the pixels in an image.
 *
 * img: pointer to the image to print
 *
 * Returns: nothing
 */
void print_image(struct image *img);

/* create_negative: create new negative ppm
 *
 * input: a pointer to the image to negate
 *
 * Returns: a pointer to the negated image
 */
struct image *create_negative(struct image *input);

/* create_greyscale: create new greyscale image
 *
 * input: pointer to the image to covert
 *
 * Returns: a pointer to a greyscale version of the image
 */
struct image *create_greyscale(struct image *input);

/* blur: create new blurred image
 *
 * input: a pointer to the image to blur
 * size: size of area around a pixel to blur (an odd integer)
 *
 * Returns: a pointer to the blurred image
 */
struct image *blur(struct image *input, int size);

#endif