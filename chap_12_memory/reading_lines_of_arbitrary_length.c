#include <stdio.h>
#include <stdlib.h>

#include "../tutorials.h"

/* Chapter 12.5.1
 *
 * Demonstration of using realloc() to grow a buffer as more data are read
 * and using realloc() to shrink a buffer down to the perfect size once data are read
 * */
#ifdef MEMORY_ARBITRARY_LENGTH
char *readline(FILE *fp){
    int offset = 0; // Index next char goes in the buffer;
    int bufsize = 4; // Preferably a power of 2 initial size
    char *buf; // THE buffer
    int c; // The character we've read in

    buf = malloc(bufsize); // Allocate initial buffer

    if(buf == NULL){ // Error check
        perror("Could not allocate buffer!\n");
        return NULL;
    }

    // Main loop -- read until newline (end of line) or EOF (end of file)
    while(c=fgetc(fp), c!='\n' && c != EOF){
        // Check if we're out of room in the buffer accounting
        // for the extra byte for the NUL terminator
        if(offset == bufsize -1){ // -1 for NUL terminator
            bufsize *=2; // 2x the space

            char *new_buf = realloc(buf, bufsize);

            if(new_buf == NULL){
                perror("Could not grow buffer!\n");
                free(buf); // On error, free and bail!

                return NULL;
            }

            buf = new_buf; // Successful realloc
        }

        buf[offset++] = c; // Add the byte onto the buffer
    }

    // We have now hit the end of line '\n' OR EOF

    // If at EOF and we read no bytes, free the buffer and return NULL
    // to indicate we're at EOF
    if(c == EOF && offset == 0){
        printf("End of file reached\n");
        free(buf);
        return NULL;
    }

    // Shrink to fit
    if(offset < bufsize -1){ // If we're short of the end
        char *new_buf = realloc(buf, offset+1); // +1 for NUL terminator

        // If successful, point buf to new_buf;
        // otherwise we'll just leave buf where it is
        if(new_buf != NULL){
            buf = new_buf;
        }
    }

    // Add the NUL terminator
    buf[offset] = '\0';

    return buf;
}

int main(void){
    FILE *fp = fopen("foo.txt", "r");

    if(!fp){
        perror("Could not open file!\n");
        return 1;
    }

    char *line;

    while((line = readline(fp)) != NULL){
        printf("%s\n", line);
        free(line);
    }

    fclose(fp);

    return 0;
}
#endif