#include <math.h>
#include <stdio.h>
#include <stdlib.h>

struct point {
  double x;
  double y;
};

struct circle {
  struct point p;
  double radius;
};

/*
 * midpoint: compute the distance between two points
 *
 * p1: first point
 * p2: second point
 *
 * Returns: the distance between p1 and p2.
 */
double distance(struct point p1, struct point p2) {
  double xs = pow(p1.x - p2.x, 2);
  double ys = pow(p1.y - p2.y, 2);
  return sqrt(xs + ys);
}

/*
 * midpoint: compute the point that is the midpoint between
 *   two points
 *
 * p1: first point
 * p2: second point
 *
 * Returns: the midpoint between p1 and p2.
 */
struct point midpoint(struct point p1, struct point p2) {
  double xs = (p1.x + p2.x) / 2;
  double ys = (p1.y + p2.y) / 2;

  struct point p = {.x = xs, .y = ys};
  return p;
}

int main() {
  // struct syntax
  struct point p1 = {.x = 1.0, .y = 2.0};
  p1.x = 1.1;
  printf("(%.1f, %.1f)\n", p1.x, p1.y);

  // distance
  struct point p2 = {.x = 0.0, .y = 0.0};
  struct point p3 = {.x = 1.0, .y = 1.0};
  printf("distance: %.3f\n", distance(p2, p3));

  // midpoint
  struct point p4 = midpoint(p2, p3);
  printf("point: (%.1f, %.1f)\n", p4.x, p4.y);

  // makes a copy of p4
  struct circle c = {p4, 10};
  c.p.x = 27;
  printf("circle point: (%.1f, %.1f), radius: %f\n", c.p.x, c.p.y, c.radius);
  printf("p4 point: (%.1f, %.1f)\n", p4.x, p4.y);
}
