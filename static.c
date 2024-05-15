#include <stdio.h>

#include "tutorials.h"

#ifdef STATIC
static void sum(int num);

int main(){
    sum(1);
    sum(10);
    sum(20);

    return 0;
}

static void sum(int num){
    static int current_sum = 0;

    current_sum += num;

    printf("Sum is: %d\n", current_sum);
}
#endif
