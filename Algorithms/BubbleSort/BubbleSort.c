#include "BubbleSort.h"

void swap(int* a, int* b)
{
    *a = (*a + *b) - (*b = *a);
}

void bubbleSort(int* arr, int size)
{
    int j = 0, i, isSorted = 0;
    while(!isSorted)
    {
        isSorted = 1;
        for(i = 0; i < size - j; i++)
        {
            if(arr[i + 1] < arr[i])
            {
                swap(&arr[i + 1], &arr[i]);
                isSorted = 0;
            }
        }
        j++;
    }
}
