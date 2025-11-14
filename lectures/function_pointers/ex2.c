#include <stdio.h>

typedef int (*math_op)(int, int);

// A simple function
int multiply(int a, int b) {
    return a * b;
}

int main() {
  // Declare a function pointer
  math_op operation;

  // Assign the address of multiply to the function pointer
  operation = multiply;

  // Call the function through the pointer
  int result = operation(5, 3);

  printf("Result: %d\n", result);
  return 0;
}
