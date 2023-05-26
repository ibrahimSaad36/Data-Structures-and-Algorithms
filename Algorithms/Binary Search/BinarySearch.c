#include "BinarySearch.h"
#include <string.h>

/* Time complexity: O(log N), space complexity O(1) */
/* Data must be sorted ascending */

int binarySearchRecursive(int* arr, int start, int end, int key)
{
    if(start <= end)
    {
        int middle = (start + end) / 2;
        if(arr[middle] < key)
        {
            return binarySearchRecursive(arr, middle + 1, end, key);
        }
        else if(arr[middle] > key)
        {
            return binarySearchRecursive(arr, start, middle - 1, key);
        }
        else
        {
            return middle;
        }
    }
    return -1;
}

int binarySearch(int* arr, int key, int size)
{
    int middle, start = 0, end = size - 1, ret = -1;
    while(start <= end)
    {
        middle = (start + end) / 2;
        if(arr[middle] == key)
        {
            ret = middle;
            break;
        }
        else if(arr[middle] < key)
        {
            end = middle - 1;
        }
        else
        {
            start = middle + 1;
        }
    }
    return ret;
}

int binarySearchString(char** arr, int size, const char* key)
{
    int start = 0, end = size - 1, middle, ret = -1;
    while(start <= end)
    {
        middle = (start + end) / 2;
        if(strcmp(arr[middle], key) > 0)
        {
            /* First non matching character in arr[middle] is greater than than
            of key in ASCII code */
            start = middle + 1;
        }
        else if(strcmp(arr[middle], key) < 0)
        {
            /* First non matching character in arr[middle] is lower than than
            of key in ASCII code */
            end = middle - 1;
        }
        else
        {
            /* both arr[middle] and key are equal, them ket is found */
            ret = middle;
            break;
        }
    }
    return ret;
}
