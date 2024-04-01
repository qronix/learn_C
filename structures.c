#include <stdio.h>

#include "tutorials.h"

#ifdef STRUCTURES
typedef struct {
    char* name;
    int age;
} person;

int main(){
    person amy = {"amy", 69};

    printf("Name: %s. Age: %d\n", amy.name, amy.age);

    return 0;
}

#endif
