#include <stdio.h>
#include "LinearSearch.h"

int main(void)
{
    char* strs [6] = {"cat", "apple", "dog"};
    int arr [4] = {1, 4, 12, 25};

    if(linearSearch(arr, 25, 4) > -1)
    {
        printf("25 is found in arr\n");
    }
    else
    {
        printf("25 is not found in arr\n");
    }

    if(linearSearchString(strs, "cat", 3) > -1)
    {
        printf("cat is found in arr\n");
    }
    else
    {
        printf("cat is not found in arr\n");
    }

    return 0;
}