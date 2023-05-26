#include "LinearSearch.h"

/* Known also as sequential search, time complexity: O(N), space complexity O(1) */
/* Useful in case of random data */
int linearSearch(const int* arr, int key, int size)
{
    int ret = -1, i;
    for(i = 0; i < size; i++)
    {
        if(arr[i] == key)
        {
            ret = i;
            break;
        }
    }
    return ret;
}

int linearSearchString(char** arr, const char* key, int size)
{
    int ret = -1, i;
    for(i = 0; i < size; i++)
    {
        if(strcmp(arr[i], key) == 0)
        {
            ret = i;
            break;
        }
    }
    return ret;
}
