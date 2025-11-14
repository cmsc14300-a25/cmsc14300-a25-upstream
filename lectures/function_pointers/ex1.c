#include <stdio.h>

// A simple function
int multiply(int a, int b) {
    return a * b;
}

int main() {
    // Declare a function pointer
    int (*operation)(int, int);

    // Assign the address of multiply to the function pointer
    operation = multiply;

    // Call the function through the pointer
    int result = operation(5, 3);

    printf("Result: %d\n", result);
    return 0;
}
