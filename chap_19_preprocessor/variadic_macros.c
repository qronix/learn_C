#include <stdio.h>

#include "../tutorials.h"

/*
 * Macros can also take a variable number of arguments (variadic)
 * by using the (...) after the known, named arguments
 * All extra arguments will be in a comma separated list in the __VA_ARGS__ macro
 * */

#ifdef VARIADIC_MACROS

// Combine the first two arguments to a single number,
// then have a commalist of the rest of them:

#define X(a, b, ...) (10*(a) + 20*(b)), __VA_ARGS__

// Additional (__VA_ARGS__) can be stringified by prepending __VA_ARGS__ with #
#define Y(...) #__VA_ARGS__

// Any argument can be stringified by prepending the argument name with #
#define STR(x) #x

#define PRTINT_INT_VAL(x) printf("%s = %d\n", #x, x)

// Arguments can also be concatenated with ##
#define CAT(a, b) a ## b

// Macros can be multiline if newlines are escaped with '\'
#define PRINT_NUMS_TO_PRODUCT(a, b) {\
    int product = (a) * (b);\
    for(int i=0; i< product; i++){\
        printf("%d\n", i);\
    }\
}

int main(void) {

    printf("%d %.2f %s %d\n", X(5, 4, 3.14, "Hi!", 12));
    printf("%s\n", Y(1,2,3));
    printf("%s\n", STR(696969));

    int a = 69;

    PRTINT_INT_VAL(a);

    printf("%d\n", CAT(69, 420));

    PRINT_NUMS_TO_PRODUCT(1,10); // Outputs numbers from 0 to 9

    return 0;
}

#endif
