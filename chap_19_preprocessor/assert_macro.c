#include <stdio.h>
#include <stdlib.h>

#include "../tutorials.h"

#ifdef ASSERT_MACRO

// We can use macros to create a robust assert macro which provides
// detailed information about our assert failure
#define ASSERT_ENABLED 1

#if ASSERT_ENABLED
#define ASSERT(c, m) \
{                    \
    if(!(c)) {       \
        fprintf(stderr, __FILE__ ":%d: assertion %s failed: %s\n", \
            __LINE__, #c, m);                                     \
            exit(1);\
    }                     \
}
#else
#define ASSERT(c,m); // Define empty macro is not enabled
#endif

int main(void) {
    int x = 17;

    ASSERT(x>=18, "x must be greater than or equal to 18");

    return 0;
}


#endif
