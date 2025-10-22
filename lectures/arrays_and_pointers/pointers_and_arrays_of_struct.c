#include <stdio.h>
#include <stdlib.h>

struct point {
  double x;
  double y;
};

int main() {
  struct point p1 = {1.0, 2.0};
  struct point *p2 = &p1;
  struct point *p3 = (struct point *)malloc(sizeof(struct point));

  // notation
  p1.y = 3.0;
  (*p2).y = 4.0;  // could also write as p2->y = 4.0
  p3->y = 5.0;

  printf("p1: (%.1f, %.1f)\n", p1.x, p1.y);
  printf("p2: (%.1f, %.1f)\n", p2->x, p2->y);
  printf("p3: (%.1f, %.1f)\n", p3->x, p3->y);

  // p3 was dynamically allocated.
  // Free it when we are done with it.
  free(p3);

  // array of structs
  // stack allocated
  struct point pa1[5];
  // heap allocated
  struct point *pa2 = (struct point *)malloc(sizeof(struct point) * 5);

  // example of a struct literal used in
  // an assignment statement.
  pa1[0] = (struct point) {.x = 1.1, .y = 2.2};
  printf("pa1[0]: (%.1f, %.1f)\n", pa1[0].x, pa1[0].y);

  pa2[0] = (struct point) {.x = 3.3, .y = 4.4};
  printf("pa2[0]: (%.1f, %.1f)\n", pa2[0].x, pa2[0].y);
  // pa2 is heap allocated. free it when we are done with it.
  free(pa2);

  // stack-allocated array of struct pointers
  // allocates space for 5 pointers
  // the structs themselves need to
  // be allocated (and freed) separately.
  struct point *ps1[5];
  for (unsigned int i = 0; i < 5; i++) {
    struct point *p = (struct point *)malloc(sizeof(struct point));
    p->x = 0.0;
    p->y = 0.0;
    ps1[i] = p;
  }
  printf("\n");

  for (unsigned int i = 0; i < 5; i++) {
    printf("ps1[%d]: (%.1f, %.1f)\n", i, ps1[i]->x, ps1[0]->y);
    // free the points
    free(ps1[i]);
  }
  printf("\n");
  // we do not free ps1 itself because it is stack allocated


  // pointer to a pointer to a struct pointer
  // This allocates space for 5 pointers.
  // Space for the actual structs needs to be
  // allocated (and freed) separately.
  struct point **ps2 = (struct point **)malloc(sizeof(struct point *) * 5);
  // here are the allocations for the individual points
  for (unsigned int i = 0; i < 5; i++) {
    // calloc initializes the allocated space to zeros.
    ps2[i] = (struct point *)calloc(sizeof(struct point), 1);
  }
  printf("\n");

  // print the points and then free them.
  for (unsigned int i = 0; i < 5; i++) {
    printf("ps2[%d]: (%.1f, %.1f)\n", i, ps2[i]->x, ps2[i]->y);
    free(ps2[i]);
  }
  // free the array of pointers.
  free(ps2);
}
