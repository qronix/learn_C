#include <stdio.h>
#include <stdlib.h>
#include "tutorials.h"

#ifdef POINTERS_TWO

struct animal {
    char *name;
    int leg_count;
};

// Comparison function called by qsort
int compar(const void* elem1, const void *elem2){
    const struct animal *animal1 = elem1;
    const struct animal *animal2 = elem2;

    return animal1->leg_count - animal2->leg_count;
}

void *my_memcpy(void *dest, void *src, int byte_count){
    // Convert void*s to char*s
    char *s = src, *d = dest;

    // Now that we have char*s, they can be dereferenced
    while(byte_count--){
        *d++ = *s++; // Post-increment allows us to get / assign the value and then move to next item
    }

    return dest;
}

int my_strlen(char *s) {
    // Start scanning at the beginning of the string
    char *p = s;

    // Scan until we find the NUL character
    while (*p != '\0') {
        p++;
    }

    // Return the difference so we get the string length!
    // Note: pointer subtraction only works on pointers which
    // point to the same array
    return p - s;
}

int main(void) {
    int a[5] = {69, 420, 6969, 420420, 696969};

    // Pointer to first element
    int *p = a;

    printf("%d\n", *p); // 69
    // Pointer arithmetic uses sizeof to automagically add the
    // required bytes (or remove them) to the pointer
    // thus, p+1 points to a[1]
    printf("%d\n", *(p + 1)); // 420 blaze it

    for (int i = 0; i < 5; ++i) {
        printf("%d\n", *(p + i)); // Equivalent to p[i]
    }

    // Increment operator can be used to increment .... duh
    // the pointer address
    while (*p != 696969) {
        printf("%d\n", *p);

        p++;
    }


    char *my_string = "This are a string";

    printf("%d\n", my_strlen(my_string));


    // Array pointer equivalence THE FUNDAMENTAL FORMULA!!!!!!
    // a[b] == *(a + b)
    // These are equivalent and can be used interchangeably

    // Demonstration of array / pointer equivalence
    int b[] = {11, 22, 33, 44, 55};
    int *q = b; // q points to the first element of b, 11

    for (int i = 0; i < 5; ++i) {
        printf("%d\n", b[i]); // Array notation with b
    }

    for (int i = 0; i < 5; ++i) {
        printf("%d\n", q[i]); // Array notation with q
    }

    for (int i = 0; i < 5; ++i) {
        printf("%d\n", *(b + i)); // Pointer notation with b
    }

    for (int i = 0; i < 5; ++i) {
        printf("%d\n", *(q + i)); // Pointer notation with q
    }

    for (int i = 0; i < 5; ++i) {
        printf("%d\n", *(q++)); // Moving pointer q

        /*
         * Why b++ Causes an Error
        In the statement printf("%d\n", *(b++));, the b++ part is trying to increment the array name b.
         This is invalid because b is not a pointer variable that you can change; it is a fixed address
         representing the start of the array.
         * */
        // printf("%d\n", *(b++)); // Moving array variable -- ERROR! Does not work!
    }


    // Array / Pointer equivalence in function calls
    // A function that takes a pointer arg such as my_strlen (above)
    // can be passed either an array, or a pointer
    char x[] = "Antelopes";
    char *y = "Wombats";

    printf("%d\n", my_strlen(x)); // Works
    printf("%d\n", my_strlen(y)); // Also be working doe!

    // void*s, COWER IN FEAR MORTAL!
    /*
     * 1. You cannot do pointer arithmetic on a void*.
       2. You cannot dereference a void*.
       3. You cannot use the arrow operator on a void*, since it’s also a dereference.
       4. You cannot use array notation on a void*, since it’s also a dereference, as well
     * */

    // Our array of unsorted animaaaallllls
    struct animal anims[4] = {
            {.name="Doge", .leg_count=7},
            {.name="Pussy", .leg_count=69},
            {.name="Gandalf", .leg_count=2},
            {.name="Sneaky Snake", .leg_count=0}
    };

    // Call qsort to sort the array
    qsort(anims, 4, sizeof(struct animal), compar);

    // Print dem animulls
    for(int i=0; i<4; i++){
        printf("%d: %s\n", anims[i].leg_count, anims[i].name);
    }

    return 0;
}

#endif
