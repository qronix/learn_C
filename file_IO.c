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
    if (fp == NULL) {
        perror("Failed to open file\n");
        return 1;
    }
    int c;

    // Reading a file one character at a time
    // bleh
    while ((c = fgetc(fp)) != EOF) {
        printf("%c", c);
    }

    fclose(fp);


    FILE *fpTwo;
    char s[1024]; // Our buffer to read lines into
    int lineCount = 0;

    fpTwo = fopen("multi_line.txt", "r");
    if (!fpTwo) {
        perror("Failed to open file\n");

        return 1;
    }

    // Read a file one line at a time
    // fgets() takes our buffer, the size of the buffer, and our file
    // fgets() returns NULL when encountering EOF or an error
    while (fgets(s, sizeof s, fpTwo) != NULL) {
        printf("%d: %s", ++lineCount, s);
    }

    fclose(fpTwo);

    // This is for our whales.txt file
    FILE *fpThree;
    char name[1024]; // Bufffffffer
    float length;
    int mass;

    fpThree = fopen("whales.txt", "r");
    if (!fpThree) {
        perror("Could not find the whales!\n");
        return 1;
    }

    // Yes, we could read these with fgets() and then parse the string with sscanf() (and in some ways that’s
    //more resilient against corrupted files), but in this case, let’s just use fscanf() and pull it in directly.
    //The fscanf() function skips leading whitespace when reading, and returns EOF on end-of-file or error
    while(fscanf(fpThree, "%s %f %d", name, &length, &mass) != EOF){
        printf("%s whale, %d tonnes, %.1f meters\n", name, mass, length);
    }

    fclose(fpThree);

    // Writing to files can be accomplished with fputc() fputs() and fprintf()
    FILE *fpWrite;
    int x = 32;

    fpWrite = fopen("output.txt","w");

    if(!fpWrite){
        perror("Could not open file for write.\n");
        return 1;
    }

    fputc('B', fpWrite);
    fputc('\n', fpWrite);
    fprintf(fpWrite, "x=%d\n", x);
    fputs("Hello, world!\n", fpWrite);

    fclose(fpWrite);

    // Binary file operations
    // File mode includes a 'b' to indicate binary operation
    // Rare to see fprintf() and similar functions used with binary ops
    // because binary mode deals with streams of bytes which can contain NUL characters
    // and NUL usually indicates the end of a string. Instead, fread() and fwrite() are used

    FILE *fpByte;
    unsigned char bytes[6] = {5, 37, 0, 88,255, 12};
    fpByte = fopen("output.bin", "wb"); // wb for write binary
    if(!fpByte){
        perror("Could not open file for binary write\n");
        return 1;
    }

    // In the call to fwrite, the arguments are:
    //
    // * Pointer to data to write
    // * Size of each "piece" of data
    // * Count of each "piece" of data
    // * FILE*

    fwrite(bytes, sizeof(char), 6, fpByte);
    fclose(fpByte);

    // Reading bytes one at a time
    FILE *fpByteRead;
    unsigned char myChar;

    fpByteRead = fopen("output.bin", "rb");

    if(!fpByteRead){
        perror("Could not open file for binary read\n");
        return 1;
    }

    while(fread(&myChar, sizeof(char), 1, fpByteRead) > 0){
        printf("%d\n", myChar);
    }

    fclose(fpByteRead);

    return 0;
}


#endif
