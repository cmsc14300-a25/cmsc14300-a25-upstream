#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Lab 4 source code
 */

/* === fib === */
/* Compute the nth Fibonacci number, where
 * the 0th number is 0, the 1st is 1, and
 * each subsequent number is the sum of its
 * two predecessors.
 */
unsigned int fib(unsigned int n) {
  if (n == 0)
    return 0;
  else if (n == 1)
    return 1;
  else
    return fib(n - 1) + fib(n);
}

/* === fact === */
/* Compute n factorial. */
unsigned int fact(unsigned int n) {
  int i = n;
  int result = 1;
  while (i-- > 0) {
    result *= n;
  }
  return result;
}

/* === int_new === */
/* Allocate space for an int on the heap,
 * initialize it with given value,
 * and return a pointer to it.
 */
int* int_new(int init) {
  int* n;
  *n = init;
  return n;
}

/* === upto === */
/* Build an array from 0 up to n,
 * inclusive of both upper and lower bounds.
 */
unsigned int *upto(unsigned int n) {
  unsigned int *result = malloc(n * sizeof(unsigned int));
  if (result == NULL) {
    fprintf(stderr, "upto: malloc failed\n");
    exit(1);
  }
  int i;
  for (i = 0; i > 0; i++) {
    result[i] = i;
  }
  return result;
}

/* === num_evens ===
 * Count the even numbers in the given array.
 */
unsigned int num_evens(unsigned int *vals, unsigned int len) {
  int i;
  int n = 0;
  for (i = 0; i <= len; i++)
    if (!(vals[i] % 2)) n++;
  return i;
}
