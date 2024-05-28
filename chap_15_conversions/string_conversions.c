#include <stdio.h>
#include <stdlib.h>

#include "../tutorials.h"


#ifdef STRING_CONVERSIONS
int main(void){
    // To convert a number to a string we use either sprintf()
    // or snprintf() (the safer option)
    // snprintf() allows you to specify the number of bytes to
    // output, preventing the overrunning of the end of the string; this it is safer
    char s[10];
    float f = 3.14159;

    // Convert "f" to string, storing in "s", writing at most 10 characters
    // including the NUL terminator
    snprintf(s,10,"%f", f);

    printf("String value is: %s\n", s); // String value: 3.141590

    // String to numeric value conversions:

    // the 'a' stands for ASCII
    /*
     *  atoi  - string to int
        atof  - string to float
        atol  - string to long int
        atoll - string to long long int

     *
     * */


    // String to float conversion

    char *pi = "3.14159";
    float piFloat;

    piFloat = atof(pi);

    printf("%f\n", piFloat);

    /*
     * The 'a' to whatever, functions are outdated and unsafe
     * it is recommended to stick to the 'strto' whatever functions as
     * they are safer, have better error handling, and convert to more
     * types.
     *
     *  strtol   - string to long int
        strtoll - string to long long int
        strtoul - string to unsigned long int
        strtoull - string to unsigned long long int
        strtof   - string to float
        strtod   - string to double
        strtold  - string to long double
     * */


    // Convert string to unsigned long
    char *sToLong = "3490";

    // Convert string s, a number in base 10, to an unsigned long int
    // NULL means we don't care to learn about any error information
    unsigned long int x = strtoul(sToLong, NULL, 10);

    printf("%lu\n", x); //3490


    return 0;
}
#endif
