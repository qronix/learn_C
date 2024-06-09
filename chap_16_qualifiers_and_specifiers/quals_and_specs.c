#include <stdio.h>

#include "../tutorials.h"

#ifdef QUALIFIERS_SPECIFIERS
int main(void){
    // const pointers baby!

    // const int *p; - Can't modify what p points to
    // int const *p; - Also cannot modify what p points to

    // Nice and confusing right? Well it gets better!

    // int *const p; - We cannot modify "p" with pointer arithmetic (the value of p)
    // p++; - Compiler error!!!! What you some kinda moron?!?!

    // int x = 10;
    // int *const p = &x;

    // *p = 20; - Set 'x' to 20, no problem!

    int x = 10;
    const int *p = &x;

    printf("p value is: %d\n", *p);
    printf("x value is: %d\n", x);
    printf("address of x is: %p\n", (void*)p);
    printf("address of p++ is: %p\n", (void*)++p);

//    (*p)++;  - Invalid because p is a const int pointer!!

    int y[] = {10,20};;
    const int *q = y;
    //(*q)++; // This is a const int pointer!!! You cannot do thaaaaat!

    int *const r = y;

    (*r)++; // Valid because only the pointer (where it is pointer is const)

    // Attempt to traverse the array by incrementing the pointer
    // r++; // Not valid, because the pointer is const


    // We can also make BOTH the pointer and the value const:
    // const int *const p; - Neither p nor the pointer value can change!! BRR BRRR BRR BRR!

    const int *const s = y; // Now we cannot modify s or its value!

    // s++; // WRONG!! It is const (*const s)
    // (*s)++; // ALSO WRONG!! It is const (const int)

    /*
     * Finally, if you have multiple levels of indirection, you should const the appropriate levels. Just because a
        pointer is const, doesn’t mean the pointer it points to must also be. You can explicitly set them like in the
        following examples:
     * */

    char **t;
    t++;  // Ok - t is not const
    (*t)++; // Ok - t value is not const

    char **const u;
    u++; // Error - Pointer is const
    (*u)++; // Ok - value is not const

    char *const *v;
    v++; // Ok - The first level pointer is const, however the second level is not
    (*v)++; // Error - Dereferencing the second level, points to the first level which is const

    char *const *const w;
    w++; // Error - First level pointer is const
    (*w)++; // Error - Second level pointer is const



    // Compiler warning about "initialization discards 'const' qualifier from pointer type target
    const int z=20;
    int *a = &z;

    // This means that our pointer is not const (the lvalue) but the rvalue is const and the compiler
    // is discarding the "const-ness" of the rvalue
    // Therefore, we can try to do something like:
    *a = 40; // Undefined behavior - but this is wrong, because we don't know what will happen

    printf("%d\n", z); // Maybe 40, maybe soup?



    return 0;
}

#endif
