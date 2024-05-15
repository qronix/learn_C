#include <stdio.h>

#include "tutorials.h"

#ifdef VARIABLES

int main() {
    int a = 3;
    float b = 4.5f;
    double c = 5.25;
    double sum = a + b + c;

    printf("%f", sum);

    return 0;
}

#endif
