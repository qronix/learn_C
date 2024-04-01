#include <stdio.h>
#include <math.h>

#include "tutorials.h"

#ifdef TWO_CRYSTAL_BALLS
typedef enum Boolean {
    false,
    true
} bool;

int twoCrystalBalls(const bool breaks[], int length) {
    int jumpAmount = (int)floor(sqrt(length));

    int currentIndex = jumpAmount;

    for (; currentIndex < length; currentIndex += jumpAmount) {
        if (breaks[currentIndex]) {
            break;
        }
    }

    // Start a linear search from the last known good (non-breaking) distance
    // which is the length of our jump
    currentIndex -= jumpAmount;

    for (int j = 0; j < jumpAmount && currentIndex < length; ++j, ++currentIndex) {
        if (breaks[currentIndex]) {
            return currentIndex;
        }
    }

    return -1;
}

int main() {
    bool breaks[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1};

    int length = sizeof(breaks) / sizeof(bool);


    printf("Both balls break at floor %d", twoCrystalBalls(breaks, length));
}

#endif
