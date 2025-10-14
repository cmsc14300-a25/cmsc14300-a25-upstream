#include <stdio.h>

/* bar: array out-of-bounds examples with
 *   a local array.
 */
void bar() {
  int a[] = {1, 2, 3, 4, 5};
  int x = a[100];
  int y = a[-5];
  printf("a[100]: %d\n", x);
  printf("a[-5]:  %d\n", y);

  // segmentation fault
  a[10] = 25;

  printf("leaving bar\n");
}

/* foo: array out-of-bounds examples with
 *   an array parameter.
 */
void foo(int a[], int a_len) {
  int x = a[100];
  printf("a[100]: %d\n", x);

  int y = a[-5];
  printf("a[-5]:  %d\n", y);

  // segmentation fault
  a[a_len + 15] = 25;
}

int main() {
  int c[3];
  printf("c: %d, %d, %d\n", c[0], c[1], c[2]);

  printf("Calling bar\n");
  bar();

  printf("Calling foo\n");

  int a[] = {1, 2, 3, 4, 5};
  foo(a, 5);
}
