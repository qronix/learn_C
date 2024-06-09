#include <stdio.h>

#include "../tutorials.h"

#ifdef BIT_FIELDS
struct foo {
    unsigned int a;
    unsigned int b;
    unsigned int c;
    unsigned int d;
};

struct packed_foo {
    unsigned int a:5;
    unsigned int b:5;
    unsigned int c:3;
    unsigned int d:3;
};

struct unnamed_bit_fields_foo {
    unsigned char a:2;
    unsigned char :5; // Unnamed bit-field
    unsigned char b:1;
};

int main(void){
    // The normal size of foo takes up 16 bytes, 4 bytes per int
    printf("The size of Foo is: %zu bytes\n", sizeof(struct foo));

    // But, what if we knew that certain values only needed to take up a certain amount of bytes?
    // we van use bit fields to suggest to the C compiler that we would like to pack values into
    // a certain amount of bytes to save space

    // Through the use of bit packing, we have gotten the size of packed foo down to 4 bytes
    // a and b are 5 bits each, c and d are 3 bits each yielding 16 bits (or 4 bytes total)
    printf("The size of packed foo is: %zu bytes\n", sizeof(struct packed_foo));

    /*
     * Note: C will only pack adjacent bit fields, so something such as
     *
     * struct non_adjacent_foo {
     *  unsigned int a:1;
     *  unsigned int b;
     *  unsigned int c:1;
     *  unsigned int d;
     * }
     *
     * Will still result in 16 bytes of size since a will be packed into its 4 byte field, same with b
     * , and c, and d.
     *
     * If we rearranged the struct to:
     *
     * struct non_adjacent_foo_fixed {
     *  unsigned int a:1;
     *  unsigned int c:1;
     *  unsigned int b;
     *  unsigned int d;
     * }
     *
     * the size would be packed to 12 bytes since a and c would fill a 4 byte space and b and d would take
     * their normal 4 byte sizes
     * */

    /*
     * [Unnamed bit-fields]
     * Sometimes we might need to reserve some bits for hardware reasons, but not use the bits in code.
     * We can use unnamed bit-fields to accomplish this.
     *
     * struct unnamed_bit_fields_foo {
            unsigned char a:2;
            unsigned char :5; <-- Unnamed bit-field
            unsigned char b:1;
        };
     *
     * In unnamed_bit_fields_foo, a takes up 2 bits, the unnamed field occupies 5 bits effectively spacing out
     * the bit field so b is in the correct position
     *
     * */

    return 0;
}


#endif
