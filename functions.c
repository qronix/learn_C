#include <stdio.h>

#include "tutorials.h"

#ifdef FUNCTIONS
void print_big(int x);

int main(){
    print_big(1);
    print_big(10);
    print_big(999);

    return 0;
}

void print_big(int x){
    if(x > 10){
        printf("Dat big!\n");

        return;
    }

    printf("Dat not big!\n");
}


#endif
