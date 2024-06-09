#include <stdio.h>

#include "../tutorials.h"

#ifdef FAKE_OOP
// Since the pointer to a struct is the same as a pointer to the first element of the struct,
// you can freely cast a pointer to the struct to a pointer to the first element

struct parent {
    int a, b;
};

struct child {
    struct parent super; // MUST be first
    int c, d;
};

// Because struct parent super is the first item in the struct child, a pointer to any struct child is the same
// as a pointer to that super field

void print_parent(void *p){
    // Expects a struct parent -- but a struct child will also work because the pointer points to the struct
    // parent in the first field

    struct parent *self = p;

    printf("Parent: %d, %d\n", self->a, self->b);
}

void print_child(struct child *self){
    printf("Child: %d, %d\n", self->c, self->d);
}

int main(void){
    struct child c = {.super.a=1, .super.b=2, .c=3, .d=4};

    print_child(&c);
    print_parent(&c);

    return 0;
}


#endif
