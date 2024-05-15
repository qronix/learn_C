#include <stdio.h>

#include "tutorials.h"


/*
 * When we do any kind of I/O in C, we do so though a piece of data that you get in the form of a FILE* type.
This FILE* holds all the information needed to communicate with the I/O subsystem about which file you
have open, where you are in the file, and so on.

 The spec refers to these as streams, i.e. a stream of data from a file or from any source. I’m going to use
“files” and “streams” interchangeably, but really you should think of a “file” as a special case of a “stream”.
There are other ways to stream data into a program than just reading from a file.


 * */

#ifdef FILE_IO

int main(void) {
    FILE *fp; // Variable represents open file

    fp = fopen("hello_world.txt", "r");
    if(fp == NULL){
        perror("Failed to open file\n");
        return 1;
    }
    int c;

    while((c= fgetc(fp))!= EOF){
    printf("%c\n", c);
    }
    
    fclose(fp);

    return 0;
}


#endif
