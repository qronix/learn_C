#include <stdio.h>

#include "tutorials.h"

#ifdef ARRAYS

int main(){
    int average;
    int grades[3];

    grades[0] = 80;
    grades[1] = 85;
    grades[2] = 90;

    average = (grades[0] + grades[1] + grades[2]) / 3;

    printf("The average of the grades is: %d", average);

    return 0;
}

#endif
