#include <stdio.h>

#include "tutorials.h"

#ifdef POINTERS
int main(){
    int n = 68;
    int* n_ptr = &n;

    *n_ptr += 1;

    printf("N is: %d\n", n);

    return 0;
}
#endif