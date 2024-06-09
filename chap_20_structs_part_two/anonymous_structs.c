#include <stdio.h>

#include "../tutorials.h"

#ifdef ANONYMOUS_STRUCTS
// Anonymous struct. Notice how it does not have a name!!!!!!!!!!!!
struct {
    char *name;
    int leg_count, speed;
} ma_animal; // Anonymous structs represent a type, so this is now the ma_animal type

// The more correct way to use anonymous structs for type definitions is, well, using typedef

typedef struct {
    char *name;
    int leg_count, speed;
} animal; // New type!

int main(void){


    return 0;
}
#endif
