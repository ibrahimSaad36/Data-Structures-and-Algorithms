#include "BinarySearch.h"
#include <stdio.h>

int main(void)
{
    int arr[5] = {1, 10, 25, 26, 30};
    char* strs [6] = {"cat", "apple", "dog"};

    if(binarySearch(arr, 25, 5) > -1)
    {
        printf("25 is found in arr\n");
    }
    else
    {
        printf("25 is not found in arr\n");
    }

    if(binarySearchString(strs, 3, "cat") > -1)
    {
        printf("cat is found in arr\n");
    }
    else
    {
        printf("cat is not found in arr\n");
    }

    return 0;
}