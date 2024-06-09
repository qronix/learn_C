#include <stdio.h>


#include "../tutorials.h"

#ifdef STATIC_EXAMPLE
/*
 * static has two meanings, depending on if the variable is file or block scope
 *
 * static in block scope means "I just want a single instance of this variable to exist, shared between calls."
 *
 * static in block scope with an initializer will only be initialized one time on program startup, not each time
 * the function is called
 *
 * static in the file scope means the variable is global in the file and only accessible from the file it
 * is defined
 * */

void counter (void){
    static int count = 1; // This is initialized one time

    printf("This has been called %d time(s)\n", count);

    count++;
}

int main(void){
    counter(); // "This has been called 1 time(s)
    counter(); // "This has been called 2 time(s)
    counter(); // "This has been called 3 time(s)
    counter(); // "This has been called 4 time(s)

    return 0;
}
#endif
