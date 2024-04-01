#include <stdio.h>
#include <stdlib.h>
#include "tutorials.h"

#ifdef DYNAMIC_ALLOC
typedef struct {
    char* name;
    int age;
} person;

int main(){
    person* alex = malloc(sizeof(person));

    alex->name = "Alex";
    alex->age = 69;

    printf("Name: %s | Age: %d\n", alex->name, alex->age);

    free(alex);

    return 0;
}


#endif
