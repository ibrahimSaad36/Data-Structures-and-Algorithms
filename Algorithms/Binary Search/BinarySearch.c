#include "BinarySearch.h"

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
