#include <stdio.h>
#include <stdlib.h>

#include "../tutorials.h"

#ifdef MEMORY_REALLOCATION
int main(void){
    // Allocate space for 20 floats
    float *p = malloc(sizeof(float) * 20);

    // Assign them fractional values
    for(int i =0; i<20; ++i){
        p[i] = i/20.f;
    }

    // Oh nooooess! We actually wanted 40 values!!!
    float *new_p = realloc(p, sizeof(*p * 40));

    if(new_p == NULL){
        printf("Error reallocating!\n");
        free(p);
        return 1;
    }

    // If it was successful, reassign p
    p = new_p;


    /*
     * Note:
     *  char *p = malloc(3490);
        char *p = realloc(NULL, 3490);

        Are equivalent, and realloc(NULL, x); will frequently be used as a
        concise way of performing malloc without having to use malloc and realloc
     * */

    // Assign new elements values in the range of 1.0 - 2.0
    for(int i=20; i<40; ++i){
        p[i] = 1.0 + (i-20) / 20.f;
    }

    // Print all values in the array
    for (int i=0; i<40; ++i){
        printf("%f\n", p[i]);
    }

    free(p);

    return 0;
}


#endif
