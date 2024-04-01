#include <stdio.h>

#include "tutorials.h"

#ifdef FUNC_ARGS
typedef struct {
    char* name;
    int age;
} person;

void birthday(person* pers);

int main(){
    person sabina = {name: "Sabina", age: 17};

    birthday(&sabina);

    printf("%s is now %d years old!\n", sabina.name, sabina.age);
    
    return 0;
}

void birthday(person* pers){
    pers->age++;
}


#endif
