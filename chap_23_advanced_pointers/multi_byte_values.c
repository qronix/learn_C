#include <stdio.h>

#include "../tutorials.h"

#ifdef MULTI_BYTE_VALUES
struct foo {
    char a;
    int b;
};

int main(void) {
    // By iterating over the byte values of any object,
    // we get its object representation. Two things with
    // the same object representation in memory (the same byte values)
    // are equal

    // The compiler used for this code took the liberty of adding three
    // bytes of padding between our char value 'a' and the int value 'b'
    // Due to this padding, the object representation of x is
    // 12 00 00 00 (padding for 'a') 78 56 34 12
    struct foo x = {0x12, 0x12345678};
    unsigned char *p = (unsigned char *) &x;

    for (size_t i = 0; i < sizeof x; i++) {
        printf("%02X\n", p[i]);
    }

    return 0;
}

#endif
