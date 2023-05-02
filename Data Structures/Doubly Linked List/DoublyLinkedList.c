#include "DoublyLinkedList.h"

static int delete_node(DLinkedList* linkedList, Node* node);

DLinkedList* createDLinkedList(void)
{
    DLinkedList* list = (DLinkedList*) malloc(sizeof(DLinkedList));
    if(list)
    {
        list->start = list->end = NULL;
        list->size = 0;
    }
    return list;
}

Node* createNode(void)
{
    Node* node = (Node*) malloc(sizeof(Node));
    if(node)
    {
        node->next = node->prev = NULL;
    }
    return node;
}

int appendNode(DLinkedList* linkedList, Node* node)
{
    int ret = 0;
    if(node && linkedList)
    {
        if(linkedList->start == NULL && linkedList->end == NULL)
        {
            /* It's the first node in the list */
            linkedList->start = linkedList->end = node;
        }
        else
        {
            /* Not the first node, append to the back of list */
            node->prev = linkedList->end;
            linkedList->end->next = node;
            linkedList->end = node;
        }
        linkedList->size++;
        ret = 1;
    }
    return ret;
}

int insertNode(DLinkedList* linkedList, Node* node, int index)
{
    int ret = 0, i;
    if(linkedList && node)
    {
        if(linkedList->start == NULL)
        {
            /* Empty list */
            if(index == 0)
            {
                linkedList->start = linkedList->end = node;
                linkedList->size++;
                ret = 1;
            }
            else
            {
                ret = -1;
            }
        }
        else
        {
            if(index == 0)
            {
                /* Insert at the start */
                linkedList->start->prev = node;
                node->next = linkedList->start;
                linkedList->start = node;
                linkedList->size++;
                ret = 1;
            }
            else if(index > 0)
            {
                Node* current = linkedList->start;
                for(i = 0; i < (index-1); i++)
                {
                    current = current->next;
                }
                if(current->next == NULL)
                {
                    /* last element in the list */
                    node->prev = current;
                    current->next = node;
                    linkedList->end = node; 
                }
                else
                {
                    node->prev = current;
                    node->next = current->next;
                    current->next->prev = node;
                    current->next = node;
                }
                linkedList->size++;
                ret = 1;
            }
            else
            {
                ret = -1;
            }
        }
    }
    return ret;
}

int deleteNode(DLinkedList* linkedList, Node* node)
{
    return delete_node(linkedList, node);
}

Node* searchNode(DLinkedList* linkedList, int data)
{
    Node* ret = NULL;
    if(linkedList)
    {
        if(linkedList->start == NULL && linkedList->end == NULL)
        {
            /* Empty list */
            ret = NULL;
        }
        else
        {
            Node* current = linkedList->start;
            while(current && (current->data != data))
            {
                current = current->next;
            }
            ret = current;
        }
    }
    return ret;
}

int peekFirst(DLinkedList* linkedList, Node* fisrtNode)
{
    int ret = 0;
    if(linkedList)
    {
        if(linkedList->start == NULL && linkedList->end == NULL)
        {
            ret = -1;
        }
        else
        {
            fisrtNode = linkedList->start;
            linkedList->start = linkedList->start->next;
            linkedList->start->prev = NULL;
            linkedList->size--;
            ret = 1;
        }
    }
    return ret;
}

int peekLast(DLinkedList* linkedList, Node* lastNode)
{
    int ret = 0;
    if(linkedList)
    {
        if(linkedList->start == NULL && linkedList->end == NULL)
        {
            ret = -1;
        }
        else
        {
            lastNode = linkedList->end;
            linkedList->end = linkedList->end->prev;
            linkedList->end->next = NULL;
            linkedList->size--;
            ret = 1;
        }
    }
    return ret;
}

int getFirst(DLinkedList* linkedList, int* fisrtNode)
{
    int ret = 0;
    if(linkedList)
    {
        if(linkedList->start == NULL && linkedList->end == NULL)
        {
            ret = -1;
        }
        else
        {
            if(fisrtNode)
            {
                *fisrtNode = linkedList->start->data;
                ret = 1;
            }
        }
    }
    return ret;
}

int getLast(DLinkedList* linkedList, int* lastNode)
{
    int ret = 0;
    if(linkedList)
    {
        if(linkedList->start == NULL && linkedList->end == NULL)
        {
            ret = -1;
        }
        else
        {
            if(lastNode)
            {
                *lastNode = linkedList->end->data;
                ret = 1;
            }
        }
    }
    return ret;
}

void printNodeData(DLinkedList* linkedList, Node* node)
{
    if(linkedList)
    {
        printf("-------------------------------------------------\n");
        if(linkedList->start == NULL && linkedList->end == NULL)
        {
            printf("Linked list is empty!\n");
        }
        else
        {
            Node* current = linkedList->start;
            while(current && (current != node))
            {
                current = current->next;
            }
            if(current)
            {
                /* Found node */
                printf("Node data is: %d\n", current->data);
            }
            else
            {
                printf("Node not found!\n");
            }
        }
        printf("-------------------------------------------------\n");
    }
}

void printAllElements(DLinkedList* linkedList)
{
    if(linkedList)
    {
        printf("-------------------------------------------------\n");
        if(linkedList->start == NULL && linkedList->end == NULL)
        {
            printf("Linked list is empty!\n");
        }
        else
        {
            int i = 0;
            Node* current = linkedList->start;
            while(current)
            {
                printf("Node no: %d has data: %d\n", i+1, current->data);
                current = current->next;
                i++;
            }
        }
        printf("-------------------------------------------------\n");
    }
}

void deleteDLinkedList(DLinkedList* linkedList)
{
    if(linkedList)
    {
        Node* current = linkedList->start, *next;
        while(current)
        {
            next = current->next;
            free(current);
            current = next;
        }
        linkedList = NULL;
    }
}

int getListLength(DLinkedList* linkedList)
{
    int ret = -1;
    if(linkedList)
    {
        ret = linkedList->size;
    }
    return ret;
}

static int delete_node(DLinkedList* linkedList, Node* node)
{
    int ret = 0;
    if(node && linkedList)
    {
        if(linkedList->start == NULL && linkedList->end == NULL)
        {
            /* Empty list */
            ret = -1;
        }
        else
        {
            if(linkedList->start == node && linkedList->end == node)
            {
                /* only one node */
                free(node);
                linkedList->start = linkedList->end = NULL;
                linkedList->size--;
                ret = 1;
            }
            else if(linkedList->start == node)
            {
                /* First node in the list */
                linkedList->start = linkedList->start->next;
                linkedList->start->prev = NULL;
                free(node);
                ret = 1;
            }
            else if(linkedList->end == node)
            {
                /* Last element in the list */
                linkedList->end = linkedList->end->prev;
                linkedList->end->next = NULL;
                free(node);
                linkedList->size--;
                ret = 1;
            }
            else
            {
                /* Node in between first and end */
                Node* current;
                while(current && (current != node))
                {
                    current = current->next;
                }
                if(current)
                {
                    /* Found the node, delete it */
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                    free(current);
                    linkedList->size--;
                    ret = 1;
                }
                else
                {
                    /* Couldn't find the node */
                    ret = -1;
                }
            }
        }
    }
    return ret;
}
