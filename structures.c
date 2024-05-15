#include <stdio.h>

#include "tutorials.h"

#ifdef STRUCTURES
struct car {
    char *name;
    float price;
    int speed;
};

void set_price(struct car *c, float new_price);

int main(void){
    struct car saturn;

    // Naive struct initialization
    saturn.name = "Saturn SL/2";
    saturn.price = 15999.99f;
    saturn.speed = 175;

    printf("Name %s\n", saturn.name);
    printf("Price %.2f\n", saturn.price);
    printf("Speed %d\n", saturn.speed);

    // Note: Variable order is REQUIRED to match the order defined in the struct!!!!
    struct car supra = {"'94 Toyota Supra Mark IV", 150000.00f, 220};

    printf("Name %s\n", supra.name);
    printf("Price %.2f\n", supra.price);
    printf("Speed %d\n", supra.speed);

    // The better way to initialize a struct (order independent)
    // Any missing field designators are initialized to zero
    struct car skyline = {.price=300000.00f, .speed=240, .name="'98 Nissan Skyline GT-R 34"};

    printf("Name %s\n", skyline.name);
    printf("Price %.2f\n", skyline.price);
    printf("Speed %d\n", skyline.speed);

    set_price(&skyline, 69.99f);

    printf("\r\n");
    printf("Name %s\n", skyline.name);
    printf("Price %.2f\n", skyline.price);
    printf("Speed %d\n", skyline.speed);
    // Passing structs to functions
    // 1. Pass the struct
    // OR
    // 2. Pass a pointer to the struct

    // Passing without a pointer will, as with EVERYTHING, pass a COPY to the function
    // Passing a struct via pointer is useful for:
    // 1. The function needs to make changes to struct values
    // 2. The struct is large, and it would be more expensive to copy the struct
    // onto the stack than to just copy a pointer to the struct

    return 0;
}

void set_price(struct car *c, float new_price){

    // Equivalent to:
    // (*c).price = new_price
    c->price = new_price;
}

#endif
