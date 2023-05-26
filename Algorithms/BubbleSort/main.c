#include <stdio.h>
#include "BubbleSort.h"

int main(void)
{
    int arr [5] = {12, 0, 36, 25, -1}, i;

    printf("Before sorting the array: \n");

    for(i = 0; i < 5; i++)
    {
        printf("%d\t", arr[i]);
    }

    bubbleSort(arr, 5);

    printf("\nAfter sorting the array: \n");

    for(i = 0; i < 5; i++)
    {
        printf("%d\t", arr[i]);
    }

    return 0;
}