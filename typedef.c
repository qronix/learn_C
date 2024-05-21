#include <stdio.h>

#include "tutorials.h"

#ifdef TYPEDEF_TUT
int main(void){

    // typedef can be used for aliasing
    typedef int age;
    age myAge = 19;

    typedef struct animal {
        char *name;
        int legCount, speed;
    } animal;

    // This can be defined as an anonymous struct
    typedef struct {
        char *name;
        int legCount;
        int speed;
    } animalTwo;

    typedef struct {
        int x;
        int y;
    } point;

    point p = {.x =69, .y=420};

    // Avoid using typedef with pointers as it obscures the fact the alias is a pointer
}
#endif
