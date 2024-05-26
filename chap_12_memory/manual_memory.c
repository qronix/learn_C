#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../tutorials.h"

#ifdef MANUAL_MEMORY
// Local variables are allocated on the stack
// Manually allocated memory is on the heap

int main(void){
    // Allocate memory for one integer
    // malloc returns NULL if unable to allocate memory
    int *p = malloc(sizeof(int));

    *p = 69; // Store something in our memory

    printf("%d\n", *p);

    // Free the memory to prevent memory leak
    free(p);

    // *p = 420 -> Results in Error: Undefined Behavior! Use after free()!

    int *q = malloc(sizeof(int)*10); // Holds 10 ints, but is filled with garbage data
    memset(q,0,sizeof(int)*10); // Zeros the memory space allocated with malloc

    free(q);

    // Memory can be allocated and cleared simultaneously via calloc()
    int *r = calloc(sizeof(int), 10);

    free(r);

    return 0;
}

#endif
