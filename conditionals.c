#include <stdio.h>

#include "tutorials.h"

#ifdef CONDITIONALS

void guessNumber(int guess) {
    if(guess == 555) {
        printf("Your guess is correct CUH!\n");

        return;
    }

    if(guess > 555) {
        printf("Your guess is toooooooo high wooooowwweeeee!\n");

        return;
    }

    printf("WOOOOOWWwwwwwwEEEEE! Your guess is toooooooooo loooooow!\n");
}

int main() {
    guessNumber(500);
    guessNumber(600);
    guessNumber(555);
}

#endif