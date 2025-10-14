#include <stdio.h>

int main() {

    // array variables are pointers
    double b[] = {1.1, 2.2, 3.3};
    printf("b:        %p\n", b);
    printf("b + 1:    %p\n", b + 1);
    printf("b + 2:    %p\n", b + 2);
    printf("\n");

    printf("*b:       %f\n", *b);
    printf("*(b + 1): %f\n", *(b + 1));
    printf("*(b + 2): %f\n", *(b + 2));
    printf("\n");

    printf("b[0]:     %f\n", b[0]);
    printf("b[1]:     %f\n", b[1]);
    printf("b[2]:     %f\n", b[2]);
    printf("\n");
}
