#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// defines two constants
enum shape_tag { CIRCLE, SQUARE };

struct point {
  double x;
  double y;
};

struct circle {
  struct point center;
  double radius;
};

struct square {
  struct point topleft;
  double side;
};

union shape {
  struct circle c;
  struct square s;
};
struct tagged_shape {
  enum shape_tag tag;
  union shape shape;
};

void print_tagged_shape(struct tagged_shape s) {
  switch (s.tag) {
    case CIRCLE:
      printf("Circle: center: (%.2f, %.2f) radius: %.2f\n", s.shape.c.center.x,
             s.shape.c.center.y, s.shape.c.radius);
      break;
    case SQUARE:
      printf("Square: top left: (%.2f, %.2f) side length: %.2f\n",
             s.shape.s.topleft.x, s.shape.s.topleft.y, s.shape.s.side);
      break;
    default:
      fprintf(stderr, "print_tagged_shape: invalid tag\n");
      exit(1);
  }
}

double compute_area(struct tagged_shape s) {
  switch (s.tag) {
    case CIRCLE:
      return M_PI * s.shape.c.radius * s.shape.c.radius;
    case SQUARE:
      return s.shape.s.side * s.shape.s.side;
    default:
      fprintf(stderr, "area: invalid tag");
  }
}

int main() {
  struct tagged_shape s1;
  s1.tag = CIRCLE;
  s1.shape.c.center.x = 1;
  s1.shape.c.center.y = 2;
  s1.shape.c.radius = 5;

  print_tagged_shape(s1);
  printf("s1 area: %f\n", compute_area(s1));

  struct tagged_shape s2;
  s2.tag = SQUARE;
  s2.shape.s.topleft.x = -1;
  s2.shape.s.topleft.y = -1;
  s2.shape.s.side = 2;


  print_tagged_shape(s2);
  printf("s2 area: %f\n", compute_area(s2));
}
