#include <stdio.h>

#include "tutorials.h"


#ifdef RECURSION
int factorial(int number);

int factorial(int number){
   if(number > 1){
       return number * factorial(number - 1);
   }else{
       return 1;
   }
}

int main(){

    int result = factorial(16);

    printf("%d", result);

    return 0;
}

#endif
