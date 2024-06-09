#include <stdio.h>

#include "../tutorials.h"

/*
 * restrict is a hint to the compiler that a particular piece of memory will only be accessed by one pointer
    and never another. If a developer declares a pointer to be restrict and then accesses the object it points to
    in another way, the behavior is undefined.
    Basically you’re telling C, “Hey—I guarantee that this one single pointer is the only way I access this memory,
    and if I’m lying, you can pull undefined behavior on me.”
 *
 * */


#ifdef RESTRICT
void swap(int *restrict a, int *restrict b){
    int t;

    t = *a;
    *a = *b;
    *b = t;
}

int main(void){
    int x = 10, y = 20;

    swap(&x, &y); // OK, "a" and "b", above, point to different things
    swap(&x, &x); // Undefined behavior! "a" and "b" point to the same thing!

    return 0;
}

/*
 * Related qualifiers
 *
 * volatile:
 *  tells the compiler that a value might change behind its back and should be looked up every time.
    An example might be where the compiler is looking in memory at an address that continuously updates
    behind the scenes, e.g. some kind of hardware timer.
    If the compiler decides to optimize that and store the value in a register for a protracted time, the value in
    memory will update and won’t be reflected in the register.
    By declaring something volatile, you’re telling the compiler, “Hey, the thing this points at might change
    at any time for reasons outside this program code.”
 *
 *
 * */
#endif
