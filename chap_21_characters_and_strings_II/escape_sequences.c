#include <stdio.h>
#include <unistd.h>

#include "../tutorials.h"

#ifdef ESCAPE_SEQUENCES
int main(void){
    for(int i=10; i>=0; i--){
        printf("\rT minus %d second%s... \b", i, i != 1? "s":"");

        fflush(stdout); // Force output to update

        sleep(1); // Delay 1 second
    }

    printf("\rBOOOOOOM!!!!    \n");

    return 0;
}
#endif
