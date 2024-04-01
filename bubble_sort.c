#include <stdio.h>

#include "tutorials.h"
#include "array.h"

#ifdef BUBBLE_SORT
void bubbleSort(Array array);

void bubbleSort(Array array)
{
    if (!array.size)
    {
        printf("Array is empty");
    }

    if (array.size == 1)
    {
        printf("%d", ((int*)array.array)[0]);

        return;
    }

    int* arr = array.array;

    for (int i = 0; i < array.size; ++i)
    {
        for (int j = 0; j < array.size - 1 - i; ++j)
        {
            const int a = arr[j];
            const int b = arr[j + 1];

            if (b < a)
            {
                const int temp = b;

                arr[j + 1] = a;
                arr[j] = temp;
            }

            for (int k = 0; k < array.size; ++k)
            {
                printf("%d", arr[k]);

                if (k < array.size - 1)
                {
                    printf(" ");
                }
            }

            printf("\r\n");
        }

        printf("***************************************\r\n");
    }

    for (int i = 0; i < array.size; ++i)
    {
        printf("%d", arr[i]);

        if (i < array.size - 1)
        {
            printf(" ");
        }
    }
    printf("\n");
}

int main()
{
    int arr[] = {4, 69, 420, -4, -4, -5, 0, 0, 0, 0, 33, 333, 420, 420, 69};

    const Array unsortedArray = {
        arr,
        sizeof(arr) / sizeof(arr[0]),
        sizeof(arr[0])
    };

    bubbleSort(unsortedArray);

    return 0;
}

#endif
