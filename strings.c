#include <stdio.h>
#include <string.h>
#include "tutorials.h"

#ifdef STRINGS
int my_strlen(char *s){
    int count = 0;

    while(s[count] != '\0')
        ++count;

    return count;
}

int main(){

    // Strings are a char pointer to the first
    // character in the string
    char *s = "My string!\n";

    // Strings can also be defined as an array
    char t[] = "My other string\n";

    // Use the %s format specifier to print a string
    printf("%s\n", s);
    printf("%s\n", t);

    // Use the %c format specifier to print a character
    for (int i = 0; i < 11; ++i)
        printf("%c", s[i]);

    for (int i = 0; i < 16; ++i)
        printf("%c", t[i]);

    // String literals are immutable
    // this is undefined behavior
    // s[0] = 'z';

    // However, character arrays are mutable
    t[0] = 'z';

    for (int i = 0; i < 16; ++i)
        printf("%c", t[i]);

    // Use strlen() from <string.h> to get the length of a string
    // Remember C uses the \0 (NUL character) to terminate a string
    // The NUL character is automatically included in the string when
    // a string is initialized with double quotes
    printf("The length of string s is: %zu\n", strlen(s));
    printf("The length of string t is: %zu\n", strlen(t));

    printf("My strlen function got length of s as: %d\n", my_strlen(s));
    printf("My strlen function got length of t as: %d", my_strlen(t));

    // Copying a string is done via strcpy(dest, source)
    // Though you should use strncpy(dest, source, size)
    // Recall that strings are character array pointers
    // therefore, if we did this:
    // s=t;
    // we are just copying the pointer to the start of t to s
    // If we were to mutate s[0] this would change both s[0] and t[0]
    // because they are pointing to the same thing e.g. are the same thing
    char u[100];

    strcpy(u, t);

    return 0;
}

#endif
