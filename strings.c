#include <stdio.h>
#include <string.h>
#include "tutorials.h"

#ifdef STRINGS
int main(){

    char* first_name = "John";
    char last_name[] = "doe";
    char name[100];

    last_name[0] = 'B';
    sprintf(name, "%s %s", first_name, last_name);
    if(strncmp(name, "John Boe", 100) == 0){
        printf("Done\n");
    }
    name[0] = '\0';
    strncat(name, first_name, 4);
    strncat(name, last_name,20);
    printf("%s\n",name);
    printf("First name: %s\n", first_name);
    printf("Last name: %s\n", last_name);

    return 0;
}

#endif
