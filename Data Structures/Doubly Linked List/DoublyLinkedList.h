#ifndef DOUBLY_DLinkedList_H
#define DOUBLY_DLinkedList_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;
    struct Node* prev;
}Node;

typedef struct
{
    int size;
    Node* start;
    Node* end;
}DLinkedList;

/******************************************************************
 * Description: This function is used to create a linked list
 * Inputs: none (void)
 * Return: returns a pointer to a created linked list (if allocated successfully)
           or returns a NULL pointer, so you have to check the return value
           before just using it directly
*******************************************************************/
DLinkedList* createDLinkedList(void);


/******************************************************************
 * Description: This function is used to create a new node
 * Inputs: none (void)
 * Return: returns a pointer to a created node (if allocated successfully)
           or returns a NULL pointer, so you have to check the return value
           before just using it directly
*******************************************************************/
Node* createNode(void);


/******************************************************************
 * Description: This function is used to append a node to the back of the list
 * Inputs: DLinkedList* (pointer to the list)
           Node* (pointer to the node to be added)
 * Return: int (if 0: couldn't add node as node is NULL or the pointer to linkedList is NULL
           , if 1: node added successfully)
*******************************************************************/
int appendNode(DLinkedList* linkedList, Node* node);


/******************************************************************
 * Description: This function is used to insert a new node to a specific index in the list
 * Inputs: DLinkedList* (pointer to the linked list itself)
           Node* (pointer to the node to be inserted)
           int (a valid index to insert the index at)
 * Return: int (0: if node is NULL or the pointer to linkedList is NULL)
               (-1: if index is invalid)
               (1: if node is inserted successfully)
*******************************************************************/
int insertNode(DLinkedList* linkedList, Node* node, int index);


/******************************************************************
 * Description: This function is used to delete a node
 * Inputs: DLinkedList* (pointer to the linked list)
           Node* (pointer to the node to be deleted)
 * Return: (0: if pointer to node or to linked list is NULL)
           (1: if node deleted successfully)
*******************************************************************/
int deleteNode(DLinkedList* linkedList, Node* node);


/******************************************************************
 * Description: This node is used to search about a node
 * Inputs: DLinkedList* (pointer to the linked list)
           int (the node's data to search)
 * Return: Node* (pointer to a node in the list if exists)
                 (it will be NULL if no node found with the same data)
*******************************************************************/
Node* searchNode(DLinkedList* linkedList, int data);


/******************************************************************
 * Description: This function is used to return the first node and exclude it from the list
                (you can't access the first node from the list again, similar to pop)
 * Inputs: DLinkedList* (pointer to the linked list)
           Node* (pointer to pop the first node in)
 * Return: int (0: if the pointer to the linked list is NULL)
               (-1: if linked list is empty)
               (1: if the first node poped successfully)
*******************************************************************/
int peekFirst(DLinkedList* linkedList, Node* fisrtNode);


/******************************************************************
 * Description: This function is used to return the last node and exclude it from the list
                (you can't access the last node from the list again, similar to pop)
 * Inputs: DLinkedList* (pointer to the linked list)
           Node* (pointer to pop the last node in)
 * Return: int (0: if the pointer to the linked list is NULL)
               (-1: if linked list is empty)
               (1: if the last node poped successfully)
*******************************************************************/
int peekLast(DLinkedList* linkedList, Node* lastNode);


/******************************************************************
 * Description: This function is used to get the value of the first node without 
                poping it
 * Inputs: DLinkedList* (pointer to the linked list)
           int* (to store the value back in)
 * Return: int (0: if the pointer to the linked list is NULL)
               (-1: if list is empty)
               (1: if value returned successfully)
*******************************************************************/
int getFirst(DLinkedList* linkedList, int* fisrtNode);


/******************************************************************
 * Description: This function is used to get the value of the last node without 
                poping it
 * Inputs: DLinkedList* (pointer to the linked list)
           int* (to store the value back in)
 * Return: int (0: if the pointer to the linked list is NULL)
               (-1: if list is empty)
               (1: if value returned successfully)
*******************************************************************/
int getLast(DLinkedList* linkedList, int* lastNode);


/******************************************************************
 * Description: This function is used to print a node data (will print not found if node
                doesn't exist in the list)
 * Inputs: DLinkedList* linkedList (a pointer to the linked list)
           Node* node (a pointer to node to print its data)
 * Return: None (void)
*******************************************************************/
void printNodeData(DLinkedList* linkedList, Node* node);


/******************************************************************
 * Description: This function is used to print all nodes of a linked list
                (will print node data if listed is not empty, if list is empty
                it will print that the linked list is empty)
 * Inputs: DLinkedList* (a pointer to the linked list)
 * Return: None (void)
*******************************************************************/
void printAllElements(DLinkedList* linkedList);


/******************************************************************
 * Description: This function is used to delete all nodes of a linked list
 * Inputs: DLinkedList* (a pointer to the linked list)
 * Return: None (void)
*******************************************************************/
void deleteDLinkedList(DLinkedList* linkedList);


/******************************************************************
 * Description: This function is used to get length of the list
 * Inputs: DLinkedList* (pointer to the linked list)
 * Return: int (-1: if the pointer to the linked list is NULL)
               (size of list if pointer is not NULL)
*******************************************************************/
int getListLength(DLinkedList* linkedList);

#endif
