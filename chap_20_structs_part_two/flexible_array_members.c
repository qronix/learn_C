#include <stdlib.h>
#include <string.h>

#include "../tutorials.h"

#ifdef FLEXIBLE_ARRAY_MEMBERS
struct len_string {
    int length;
    char data[]; // This only works is the flexible array (array without size) is the last field in the struct
};

struct len_string *len_string_from_c_string(char *s){
    int len = strlen(s);

    // Allocate "len" more bytes than we'd normally need
    struct len_string *ls = malloc(sizeof *ls + len);

    ls->length = len;

    // Copy the string into those extra bytes
    memcpy(ls->data, s, len);

    return ls;
}

int main (void){


    return 0;
}
#endif
