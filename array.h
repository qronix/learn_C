#ifndef ARRAY_H
#define ARRAY_H

typedef struct array {
    void* array;
    size_t size;
    size_t elementSize;
} Array;
#endif // ARRAY_H
