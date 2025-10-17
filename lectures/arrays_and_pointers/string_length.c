#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* This file contains a variety of ways to compute the
 * length of a string.
 */

unsigned int string_length0(char *s) {
  unsigned int i = 0;
  for (; s[i] != '\0'; i++) {
    // do nothing
  }
  return i;
}

unsigned int string_length1(char *s) {
  unsigned int i = 0;
  while (s[i] != '\0') {
    i++;
  }
  return i;
}

unsigned int string_length2(char *s) {
  unsigned int i = 0;
  while (s[i]) {
    i++;
  }
  return i;
}

unsigned int string_length3(char *s) {
  char *curr = s;
  while (*curr != '\0') {
    curr++;
  }
  return curr - s;  // pointer arithmetic
}

unsigned int string_length4(char *s) {
  char *curr = s;
  while (*curr) {
    curr++;
  }
  return curr - s;
}

unsigned int string_length5(char *s) {
  char *curr = s;
  while (*curr++) {
    // do nothing
  }
  // Why is the -1 necessary here but not in the previous version
  return curr - s - 1;
}

int string_length6(char *s) { return strlen(s); }

int main() {
  char *s = "Hello, world!";
  printf("string_length0: %d\n", string_length0(s));
  printf("string_length1: %d\n", string_length1(s));
  printf("string_length2: %d\n", string_length2(s));
  printf("string_length3: %d\n", string_length3(s));
  printf("string_length4: %d\n", string_length4(s));
  printf("string_length5: %d\n", string_length5(s));
  printf("string_length6: %d\n", string_length6(s));
}