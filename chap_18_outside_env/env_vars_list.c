#include <stdio.h>

#include "../tutorials.h"

extern char **environ; // MUST be extern and named "environ"

#ifdef ENV_VARS_LIST
int main(void){
    for( char **p = environ; *p != NULL; p++){
        printf("%s\n", *p);
    }

    // Or you could do this:
    for(int i =0; environ[i] != NULL; i++){
        printf("%s\n", environ[i]);
    }

    return 0;
}


#endif

