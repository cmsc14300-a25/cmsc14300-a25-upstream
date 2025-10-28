#include <stdio.h>
#include <stdlib.h>

#include "lab5.h"

/* === main ===
 * Run tests of functions above.
 */
int main(int argc, char *argv[]) {
  int i;

  printf("/*** fib ***/\n");
  unsigned int f0 = fib(0);
  unsigned int f1 = fib(1);
  unsigned int f2 = fib(2);
  printf("fib(0)\t%d\n", f0);
  printf("fib(1)\t%d\n", f1);
  printf("fib(2)\t%d\n", f2);

  printf("/*** fact ***/\n");
  unsigned int t5 = fact(5);
  unsigned int t6 = fact(6);
  unsigned int t7 = fact(7);
  printf("fact(5)\t%9d\n", t5);
  printf("fact(6)\t%9d\n", t6);
  printf("fact(7)\t%9d\n", t7);

  printf("/*** int_new ***/\n");
  int *h = int_new(99);
  printf("h\t%p\n", h);
  printf("h+1\t%p\n", h + 1);
  printf("*h\t%d\n", *h);
  free(h);

  printf("/*** upto ***/\n");
  unsigned int *arr10 = upto(10);
  for (i = 0; i <= 10; i++) printf("arr10[%d]\t%2d\n", i, arr10[i]);
  free(arr10);

  printf("/*** num_evens ***/\n");
  unsigned int e = num_evens(upto(10), 11);
  printf("num_evens(upto(10))\t%d\n", e);
  return 0;
}
