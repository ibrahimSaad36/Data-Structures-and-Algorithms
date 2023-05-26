#include <stdio.h>
#include "SelectionSort.h"

int main(void)
{
    int arr [5] = {12, 0, 36, 25, -1}, i;

    printf("Before sorting the array: \n");

    for(i = 0; i < 5; i++)
    {
        printf("%d\t", arr[i]);
    }

    selectionSort(arr, 5);

    printf("\nAfter sorting the array: \n");

    for(i = 0; i < 5; i++)
    {
        printf("%d\t", arr[i]);
    }

    return 0;
}