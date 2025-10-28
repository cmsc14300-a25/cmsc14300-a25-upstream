/*
 * CMSC 14300
 * Autumn 2025
 * Lab #5: LLDB practice
 *
 * You will modify this file as part of the lab.
 */

#include "lab5.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* === fib === */
/* See lab5.h for the header comment */
unsigned int fib(unsigned int n) {
  if (n == 0)
    return 0;
  else if (n == 1)
    return 1;
  else
    return fib(n - 1) + fib(n);
}

/* === fact === */
/* See lab5.h for the header comment */
unsigned int fact(unsigned int n) {
  int i = n;
  int result = 1;
  while (i-- > 0) {
    result *= n;
  }
  return result;
}

/* === int_new === */
/* See lab5.h for the header comment */
int *int_new(int init) {
  int *n;
  *n = init;
  return n;
}

/* === upto === */
/* See lab5.h for the header comment */
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

/* === num_evens === */
/* See lab5.h for the header comment */
unsigned int num_evens(unsigned int *vals, unsigned int len) {
  int i;
  int n = 0;
  for (i = 0; i <= len; i++) {
    if (!(vals[i] % 2)) {
      n++;
    }
  }
  return i;
}

