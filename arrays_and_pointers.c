#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "tutorials.h"

#ifdef ARRAYS_AND_PTRS
int main(){
    int** rows = malloc(3 * sizeof(int*));

    rows[0] = malloc(sizeof(int));
    rows[1] = malloc(2 * sizeof(int));
    rows[2] = malloc(3 * sizeof(int));

    rows[0][0] = 1;

    rows[1][0] = 1;
    rows[1][1] = 1;

    rows[2][0] = 1;
    rows[2][1] = 2;
    rows[2][2] = 1;

    for(int i = 0; i<3; i++){
        char result[i+1*2];
        result[0] = '\0';

        for(int j = 0; j<i+1; j++){
//            printf("%d\n",rows[i][j]);

            strcat(result, (char *) &rows[i][j]);
        }

        sprintf(result,"%s\n",result);
    }

    free(rows[0]);
    free(rows[1]);

    free(rows);

    return 0;
}
#endif
