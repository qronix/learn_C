#include <math.h>
#include <stdio.h>

#include "tutorials.h"
#include "boolean.h"
#include "array.h"

#ifdef BINARY_SEARCH

// Remember binary search assumes an ordered array
bool binarySearch(Array haystack, int needle)
{
    int low = 0;
    int high = haystack.size;

    int* arr = haystack.array;

    do
    {
        const int midPoint = floor(low + (high - low) / 2);
        const int value = arr[midPoint];

        if (value == needle)
        {
            return true;
        }

        if (value > needle)
        {
            high = midPoint;
        }
        else
        {
            low = midPoint + 1;
        }
    }
    while (low < high);

    return false;
}

int main()
{
    int haystack[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 88, 677, 6766, 454545, 99999};

    Array arr = {
        haystack,
        sizeof(haystack) / sizeof(haystack[0])
    };

    bool result = binarySearch(arr, 5);

    if (result == false)
    {
        printf("The value was not found.");
    }
    else
    {
        printf("The value was found.");
    }

    return 0;
}


#endif
