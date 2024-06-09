#include <stdio.h>

#include "../tutorials.h"

#ifdef ADVANCED_POINTERS
int main(void){
    int x = 3490; // Type: int
    int *p = &x; // Type: pointer to an int
    int **q = &p; // Type: pointer to a pointer to an int

    printf("%d %d\n", *p, **q); // 3490 3490

    printf("Address of x: %p\n", (void*)&x);
    printf("Address of p: %p\n", (void*)&p);
    printf("Address of q: %p\n", (void *)&q);

    // Recall: declaring a pointer like this, means that 'y' (THE POINTER) cannot be changed
    int *const y = &x;

    // What about multi-level constness? Such as:
    int **z = &p;

    const int **z1 = &p;

    // Can't do since p is const
//    (**z1)++;

    // The second level of indirection can be incremented (the pointer TO the int 'p')
    (*z1)++;

    // The top-most level pointer can be incremented
    z1++;

    // But what if we want to prevent these pointers from being mutated?

    // The second level pointer is const
    int *const *z2 = &p;

    // Invalid as the second level pointer is const
//    (*z2)++;
// We can increment 'p' since it is not const
    (**z2)++;

    // The top-most level pointer can be incremented as it is not const
    z2++;
    return 0;

    // How do we prevent the mutation of the top-most level pointer???

    int *const *const z3 = &p;

//    z3++; Invalid! The top-most level is const
//    (*z3)++; Invalid! The second level is const
    (**z3)++ ; // OK! p (the 'int') is not const

    // CONST IT ALLLL!!!

    const int *const *const z4 = &p;

//    z4++; Invalid! It is const
//    (*z4)++; Invalid! It too is const
//    (**z4)++; Invalid! It too too too too is const!!!!!


}
#endif
