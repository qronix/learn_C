#include <stdio.h>

#include "../tutorials.h"

#ifdef FUNCTION_POINTERS

void print_int(int n) {
    printf("%d\n", n);
}

int add(int a, int b) {
    return a + b;
}

int mult(int a, int b) {
    return a * b;
}

void print_math(int (*operation)(int, int), int x, int y) {
    int result = operation(x, y);

    printf("%d\n", result);
}

int main(void) {
    // Create a pointer to function print_int
    // Notice the arg types for the print_int prototype
    // follow the pointer in the second set of parentheses
    void (*p)(int) = print_int;

    p(69); // Call function print_int with the value of 69


    print_math(add, 4,3);
    print_math(mult,5,5);

    return 0;
}

#endif
