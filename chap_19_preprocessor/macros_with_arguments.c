#include <stdio.h>
#include <math.h> // sqrt()

#include "../tutorials.h"

#ifdef MACROS_W_ARGS

// Macros can take arguments and perform basic functions
// Functional macros are typically used for quick math operations
// Be careful about operator precedence!!!!!!
// These appear to basically be Scheme??

#define SQR(x) ((x) * (x))
#define TRIANGLE_AREA(w, h) (0.5 * (w) * (h))

#define QUADP(a, b, c) ((-(b) + sqrt((b)*(b) -4 * (a) * (c))) / (2 * (a)))
#define QUADM(a, b, c) ((-(b) - sqrt((b)*(b) -4 * (a) * (c))) / (2 * (a)))

#define QUAD(a, b, c) QUADP(a,b,c) , QUADM(a,b,c)

int main(void) {

    printf("2*x^2 + 10*x + 5 =0\n");
    printf("x = %f or x = %f\n", QUAD(2, 10, 5));

    return 0;
}

#endif
