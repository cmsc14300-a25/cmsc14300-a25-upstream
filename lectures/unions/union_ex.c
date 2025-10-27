#include <stdio.h>
#include <stdlib.h>

int main() {
  union data {
    int x;
    double y;
  };
  union data d1;
  d1.x = 5;
  printf("d1.x: %d\n", d1.x);

  // be careful. Interpretting
  printf("d1.y: %f\n", d1.y);
  printf("sizeof(d1): %lu\n", sizeof(d1));

  // Use the -> notation to access the member of a pointer to a union.
  union data *d2 = (union data *)malloc(sizeof(union data));
  d2->y = 5.5;
  printf("d2.x: %d\n", d2->x);
  printf("d2.y: %f\n", d2->y);
}