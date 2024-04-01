#include <stdio.h>
#include <stdlib.h>
#include "tutorials.h"


#ifdef ARRAY_LIST
typedef enum Boolean {
    false,
    true
} bool;

typedef struct arrayList {
    int *array;
    int size;
    int capacity;
} ArrayList;

int getSize(const ArrayList *arrList);

int getCapacity(const ArrayList *arrList);

ArrayList *createArrayList(int initialCapacity);

ArrayList *appendElement(ArrayList *arrList, int item);

ArrayList *prependElement(ArrayList *arrList, int item);

ArrayList *insertElement(ArrayList *arrList, int item, int position);

ArrayList *removeElement(ArrayList *arrList, int position);

void destroyList(ArrayList *arrList);

bool needsResizing(const ArrayList *arrList);

ArrayList *resizeList(ArrayList *arrList);

int getSize(const ArrayList *arrList) {
    return arrList->size;
}

int getCapacity(const ArrayList *arrList) {
    return arrList->capacity;
}

void printList(const ArrayList *arrList) {
    for (int i = 0; i < arrList->size; ++i) {
        printf("%d", arrList->array[i]);
    }

    printf("\n");
}

ArrayList *createArrayList(int initialCapacity) {
    int *array = malloc(sizeof(int) * initialCapacity);

    if (array) {
        ArrayList *arrayList = malloc(sizeof(ArrayList));

        if (arrayList) {
            arrayList->capacity = initialCapacity;
            arrayList->size = 0;
            arrayList->array = array;

            return arrayList;
        }

        free(array);
        array = NULL;

        return NULL;
    }

    return NULL;
}

bool needsResizing(const ArrayList *arrList) {
    return arrList->size == arrList->capacity;
}

ArrayList *prependElement(ArrayList *arrList, int item) {
    if (arrList) {
        ArrayList *updatedList = arrList;

        if (needsResizing(arrList)) {
            updatedList = resizeList(arrList);
        }

        if (updatedList) {
            for (int i = updatedList->size; i > 0; --i) {

                updatedList->array[i] = updatedList->array[i - 1];
            }

            updatedList->array[0] = item;
            updatedList->size++;

            return updatedList;
        }
    }

    return NULL;
}

ArrayList *resizeList(ArrayList *arrList) {
    int resizedCapacity = arrList->capacity * 2;
    ArrayList *resizedList = malloc(sizeof(ArrayList));

    if (resizedList) {
        int *resizedArray = realloc(arrList->array, resizedCapacity);

        if (resizedArray) {
            resizedList->capacity = resizedCapacity;
            resizedList->size = arrList->size;
            resizedList->array = resizedArray;
        }

        free(resizedArray);
        resizedArray = NULL;
    }

    free(resizedList);
    resizedList = NULL;

    return NULL;
}

int main(void) {
    ArrayList *arrayList = createArrayList(5);

    prependElement(arrayList, 69);
    printList(arrayList);

    free(arrayList);
    arrayList = NULL;

    return 0;
}

#endif
