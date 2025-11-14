#include <stdio.h>

typedef int (*binary_op)(int, int);

int add(int a, int b) { return a + b; }
int subtract(int a, int b) { return a - b; }
int multiply(int a, int b) { return a * b; }
int divide(int a, int b) { return b != 0 ? a / b : 0; }

int main() {
    // Array of function pointers
    binary_op operations[] = {add, subtract, multiply, divide};
    char *op_names[] = {"Add", "Subtract", "Multiply", "Divide"};

    int a = 10, b = 5;

    for (int i = 0; i < 4; i++) {
        printf("%s: %d\n", op_names[i], operations[i](a, b));
    }

    return 0;
}
