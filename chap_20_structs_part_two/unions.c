#include <stdio.h>

#include "../tutorials.h"


#ifdef UNIONS
/*
 * Unions are basically structs, except their fields overlap in memory. A union will be only large enough
 * for the largest field, and only a single field can be used at a time.
 * */
union foo{
    int a,b,c,d;
    float e,f;
    char g,h,i;
};
int main(void){
    union foo x;

    x.a = 12;
    printf("%d\n", x.a);

    x.f = 3.1415;
    printf("%f\n", x.f); // x.f was the last item stored in the union, effectively overwriting x.a

    printf("%d\n", x.a); // Unspecified behavior -- prints 1078529622

    /*
     * A pointer to a union can be cast to any type of the union fields
     * */
    int *foo_int_p = (int*)&x;
    float *foo_float_p = (float*)&x;

    x.a = 12;
    printf("%d\n", x.a); // 12
    printf("%d\n", *foo_int_p); // 12 also

    x.f = 3.1415;
    printf("%f\n", x.f); //3.1415
    printf("%f\n", *foo_float_p); // 3.1415, again

    // We can cast a pointer derived from a union type back to a pointer to the union
    union foo *p = (union foo *)foo_int_p;

    p->a = 69;
    x.a = 69; // These lines do the same thing

    // under the hood, all these values in a union start at the same place in memory,
    //and that’s the same as where the entire union is

    return 0;
}
#endif
