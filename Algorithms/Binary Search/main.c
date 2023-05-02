#include "BinarySearch.h"
#include <stdio.h>

int main(void)
{
    int arr[5] = {1, 10, 25, 26, 30};

    if(binarySearch(arr, 25, 5) > -1)
    {
        printf("25 is found in arr\n");
    }
    else
    {
        printf("25 is not found in arr\n");
    }

    return 0;
}