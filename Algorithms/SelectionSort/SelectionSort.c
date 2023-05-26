#include "SelectionSort.h"

void swap(int* a, int* b)
{
    *a = (*a + *b) - (*b = *a);
}

/* Not suitable for large data, time complexity O(N^2) */
void selectionSort(int* arr, int size)
{
    int i, j, minIndex = 0;
    for(i = 0; i < size - 1; i++)
    {
        minIndex = i;
        for(j = i + 1; j < size; j++)
        {
            if(arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        swap(&arr[i], &arr[minIndex]);
    }
}
