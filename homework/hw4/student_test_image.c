#include <criterion/criterion.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "image.h"
#include "util.h"

// Constants used to construct error messages
#define ASSERT_FMT_STR " %s"
#define ERR_MSG_LEN (1000)

#define READ_FILE_ERR                                             \
  ("Check the error message to see if the expected file was not " \
   "available/incorrect or if create_blk_image_failed")

/* Compare two images. This function is used to compare
 * actual and expected images when actual_expected_check
 * is true. It is used to check for input modifications
 * when actual_expected_check is false.
 */
void helper_check_images(struct image *actual, char *expected_file,
                         bool actual_expected_check) {
  struct image *expected = read_image(expected_file);
  cr_assert(expected != NULL, "%s\n", READ_FILE_ERR);

  cr_assert(actual != NULL);

  char err_msg[ERR_MSG_LEN];
  cr_assert_eq(actual->height, expected->height);
  cr_assert_eq(actual->width, expected->width);

  for (int i = 0; i < expected->height; i++) {
    for (int j = 0; j < expected->width; j++) {
      if (actual_expected_check) {
        snprintf(err_msg, ERR_MSG_LEN - 1,
                 ("Actual result (%d, %d, %d) does not match the expected "
                  "result (%d, %d, %d)\n"
                  " at pixel location (%d, %d).\n"),
                 actual->pixels[i][j].red, actual->pixels[i][j].green,
                 actual->pixels[i][j].blue, expected->pixels[i][j].red,
                 expected->pixels[i][j].green, expected->pixels[i][j].blue, i,
                 j);
      } else {
        snprintf(err_msg, ERR_MSG_LEN - 1,
                 "Input modified at pixel location (%d, %d).\n", i, j);
      }

      cr_assert_eq(actual->pixels[i][j].red, expected->pixels[i][j].red,
                   ASSERT_FMT_STR, err_msg);
      cr_assert_eq(actual->pixels[i][j].green, expected->pixels[i][j].green,
                   ASSERT_FMT_STR, err_msg);
      cr_assert_eq(actual->pixels[i][j].blue, expected->pixels[i][j].blue,
                   ASSERT_FMT_STR, err_msg);
    }
  }

  free_image(expected);
}
/********** Task 1 **********/

/* helper_create_blk_image: Do the work of one create_blk_image test
 *
 * height: height of new image
 * width: width of new image
 * test_name: test name for error messages
 */
void helper_create_blk_image(int height, int width, char *expected_file) {
  struct image *actual = create_blk_image(height, width);
  helper_check_images(actual, expected_file, true);

  // free the space allocated for the test
  if (actual != NULL) {
    free_image(actual);
  }
}

TestSuite(create_blk_image, .timeout = 60);

Test(create_blk_image, test0) {
  helper_create_blk_image(3, 4, "test-images/blk-3-4.ppm");
}

// add your Task 1 tests here 


/********** Task 4 **********/
void helper_create_negative(char *input_file, char *expected_file) {
  struct image *input = read_image(input_file);
  cr_assert(input != NULL, "%s\n", READ_FILE_ERR);

  struct image *actual = create_negative(input);
  // verify that the input has not been modified
  helper_check_images(input, input_file, false);
  // verify the result
  helper_check_images(actual, expected_file, true);

  // free the space allocated for the test
  free_image(input);
  if (actual != NULL) {
    free_image(actual);
  }
}

TestSuite(create_negative, .timeout = 60);

Test(create_negative, test0) {
  helper_create_negative("test-images/test1.ppm", "test-images/negative1.ppm");
}

// add your Task 4 tests here 

/********** Task 5 **********/

void helper_create_greyscale(char *input_file, char *expected_file) {
  struct image *input = read_image(input_file);
  cr_assert(input != NULL, "%s\n", READ_FILE_ERR);

  struct image *actual = create_greyscale(input);
  // verify that the input has not been modified
  helper_check_images(input, input_file, false);
  // verify the result
  helper_check_images(actual, expected_file, true);

  // free the space allocated for the test
  free_image(input);
  if (actual != NULL) {
    free_image(actual);
  }
}

TestSuite(create_greyscale, .timeout = 60);

Test(create_greyscale, test0) {
  helper_create_greyscale("test-images/test1.ppm",
                          "test-images/greyscale1.ppm");
}

// add your Task 5 tests here 


/********** Task 6 **********/

void helper_blur(char *input_file, int size, char *expected_file) {
  struct image *input = read_image(input_file);
  cr_assert(input != NULL, "%s\n", READ_FILE_ERR);

  struct image *actual = blur(input, size);
  // verify that the input has not been modified
  helper_check_images(input, input_file, false);
  // verify the result
  helper_check_images(actual, expected_file, true);

  // free the space allocated for the test
  free_image(input);
  if (actual != NULL) {
    free_image(actual);
  }
}

TestSuite(blur, .timeout = 60);

Test(blur, test0) {
  helper_blur("test-images/test1.ppm", 3, "test-images/blur1-3.ppm");
}

// add your Task 6 tests here 
