#ifndef LINEAR_SEARCH_H
#define LINEAR_SEARCH_H

#include <string.h>

/* Linear search also is called sequential search 
   Time complexity is O(n) 
*/

/**************************************************************
 * Description: This function is used to search about key in an array of integers
 * Inputs: int* (pointer to the array)
           int  (key to search about)
           int  (size of the array)
 * Return: (-1 if the key not found, index of the key if found)
***************************************************************/
int linearSearch(const int* arr, int key, int size);

/**************************************************************
 * Description: This function is used to search about key in an array of strings
 * Inputs: char** (pointer to the array of strings)
           char*  (key to search about)
           int  (size of the array)
 * Return: (-1 if the key not found, index of the key if found)
***************************************************************/
int linearSearchString(char** arr, const char* key, int size);

#endif
