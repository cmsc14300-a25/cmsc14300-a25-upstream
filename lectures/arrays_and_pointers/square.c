#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/* print_array: print the contents on an array
 *
 * a: the array of interest
 * len: the length of a
 *
 * Returns: nothing
 */
void print_array(int a[], int len) {
  for (unsigned int i = 0; i < len; i++) {
    printf("a[%d]: %d\n", i, a[i]);
  }
  printf("\n");
}

/* square_in_place: square the elements in an array in place
 *
 * a: the array of interest
 * len: the length of a
 *
 * Returns: nothing
 */
void square_in_place(int a[], int len) {
  for (unsigned int i = 0; i < len; i++) {
    a[i] = a[i] * a[i];
  }
}

/* square: generate a new array with the square the elements
 *   of the input array.
 *
 * a: the array of interest
 * len: the length of a
 *
 * Returns: a new array of the same length as the input array with
 *   the elements squared.
 */
int *square(int a[], int len) {
  int *rv = (int *)malloc(sizeof(int) * len);
  if (rv == NULL) {
    fprintf(stderr, "Allocation failed in square\n");
    exit(1);
  }

  for (unsigned int i = 0; i < len; i++) {
    rv[i] = a[i] * a[i];
  }
  return rv;
}

/* arrays_equal: determine whether two arrays contain
 *   the same values
 *
 * a: the first operand
 * a_len: the length of a
 * b: the second operand
 * b_len: the length of b
 *
 * Returns: true, if a and b contain the same values
 */
bool arrays_equal(int a[], int a_len, int b[], int b_len) {
  if (a_len != b_len) {
    return false;
  }
  for (unsigned int i = 0; i < a_len; i++) {
    if (a[i] != b[i]) {
      return false;
    }
  }
  return true;
}

int main() {
  int x[] = {1, 2, 3};
  int y[] = {1, 2, 3};
  int z[] = {1, 2};

  /*
  printf("array_equal(x, 3, y, 3): %d\n", arrays_equal(x, 3, y, 3));
  printf("x: %p, y: %p: x == y: %d\n", x, y, x == y);
  printf("array_equal(x, 3, z, 2): %d\n", arrays_equal(x, 3, z, 2));
  */

  printf("\nx before the square in place\n");
  print_array(x, 3);
  square_in_place(x, 3);
  printf("x after the square in place\n");
  print_array(x, 3);

  int a_one[] = {10};
  printf("\na_one before the square in place\n");
  print_array(a_one, 1);
  square_in_place(a_one, 1);
  printf("a_one after the square in place\n");
  print_array(a_one, 1);

  /*
    printf("array_equal(x, 3, y, 3): %d\n", arrays_equal(x, 3, y, 3));

    int y_copy[] = {1, 2, 3};
    int *y_squared = square(y, 3);
    printf("y_squared\n");
    print_array(y_squared, 3);
    printf("array_equal(y, 3, y_copy, 3): %d\n", arrays_equal(y, 3, y_copy, 3));
    free(y_squared);
    */
}
