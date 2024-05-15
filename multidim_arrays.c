#include <stdio.h>

#include "tutorials.h"

#ifdef MULTI_DIM_ARRAYS
int main(){
    float average = 0.f;

    int grades[][5] = {
            {80, 70, 65,89,90},
            {85,80,80,82,87}
    };

    for(int i=0; i<2; i++){
        average = 0.f;

        for(int j=0; j<5; j++){
            average += grades[i][j];
        }

    printf("The average is %.2f: ", average / 5);
    }

    return 0;
}
#endif
