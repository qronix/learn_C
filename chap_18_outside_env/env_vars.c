#include <stdio.h>
#include <stdlib.h>

#include "../tutorials.h"

#ifdef ENV_VARS

int main(void) {
    char *val = getenv("FROTZ"); // Try to get env var

// Check to make sure it exists
    if (val == NULL) {
        printf("Cannot find the FROTZ environment variable\n");
        return EXIT_FAILURE;
    }

    printf("Value: %s\n", val);

    return 0;
}

#endif
