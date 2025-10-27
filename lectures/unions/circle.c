#include <stdio.h>

struct point {
  double x;
  double y;
};

struct circle {
  struct point center;
  double radius;
};

int main() {
    struct circle c = {{.x = 0.0, .y = 0.0}, .radius = 10};
    printf("center: (%.2f, %.2f), radius: %.2f\n", 
           c.center.x, c.center.y, c.radius);
}