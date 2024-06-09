#include <stdio.h>

#include "../tutorials.h"

#ifdef NESTED_STRUCTS

#define SHIP_INFO(ship) printf("%s: %d seats, %d%% oxygen\n", ship.manufacturer, ship.ci.window_count, ship.ci.o2Level)

struct passenger {
    char *name;
    int isVIP; // Boolean
};

#define MAX_PASSENGERS 20

struct cabin_information {
    int window_count;
    int o2Level;
};

struct spaceship {
    char *manufacturer;
    struct cabin_information ci;
    struct passenger passengers[MAX_PASSENGERS];
};


int main(void) {
    // Nested structs and initializers!!!!! Yay!
    struct spaceship s = {
            .manufacturer = "Galactic Motors",
            .ci.window_count = 8, // Nested initializer!!! Ahhh freak out!!!!
            .ci.o2Level = 21
    };

    SHIP_INFO(s);
    // The above can also be written as
    struct spaceship t = {
            .manufacturer = "Galactaway",
            .ci = {
                    .window_count = 20,
                    .o2Level = 69,
            }
    };

    SHIP_INFO(t);


    struct spaceship w = {
            .manufacturer = "Supanu",
            .passengers = {
                    [0].name = "Archer, Stirling",
                    [0].isVIP = 1,
                    [1].name = "Archer, Mallory",
                    [1].isVIP = 1,
                    [2].name = "Gillette, Ray",
                    [2].isVIP = 0,

            }
    };

    printf("Passengers for %s ship: \n", w.manufacturer);

    for (int i = 0; i < MAX_PASSENGERS; ++i) {
        if (w.passengers[i].name != NULL) {
            printf("%s %s\n", w.passengers[i].name, w.passengers[i].isVIP ? "VIP" : "");
        }
    }

    return 0;
}


#endif
