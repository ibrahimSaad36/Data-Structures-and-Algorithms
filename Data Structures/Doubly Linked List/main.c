#include "DoublyLinkedList.h"
#include <conio.h>

int main(void){
    DLinkedList* list;
    char selection;
    int data;

    list = createDLinkedList();

    do{
        if(getListLength(list) == 0)
        {
            printf("**********************************\n");
            printf("List is empty, choose from the following menu, or press s to stop:\n");
            printf("1- insert new node\n");
            printf("2- append new node\n");
            printf("**********************************\n");
        }
        else
        {
            printf("**********************************\n");
            printf("List is NOT empty, choose from the following menu, or press s to stop:\n");
            printf("1- insert new node\n");
            printf("2- append new node\n");
            printf("3- search for node\n");
            printf("4- delete node\n");
            printf("5- peek first node\n");
            printf("6- peek last node\n");
            printf("7- get first node\n");
            printf("8- get last node\n");
            printf("9- get size of the list\n");
            printf("p- print all elements\n");
            printf("**********************************\n");
        }
        selection = getch();

        if(selection == '1'){
            int index;
            Node* newNode;
            newNode = createNode();
            printf("Enter the value of this node: \n");
            scanf("%d", &data);
            printf("Enter index: \n");
            scanf("%d", &index);
            newNode->data = data;
            insertNode(list, newNode, index);
        }
        if(selection == '2'){
            Node* newNode;
            newNode = createNode();
            printf("Enter the value of this node: \n");
            scanf("%d", &data);
            newNode->data = data;
            appendNode(list, newNode);
        }
        if(selection == '5'){
            Node* newNode;
            peekFirst(list, newNode);
            printf("**********************************\n");
            printf("The value of the first node is: %d\n", newNode->data);
            printf("**********************************\n");
        }
        if(selection == '6'){
            Node* newNode;
            peekLast(list, newNode);
            printf("**********************************\n");
            printf("The value of the last node is: %d\n", newNode->data);
            printf("**********************************\n");
        }
        if(selection == '7'){
            int data;
            Node* newNode;
            getFirst(list, &data);
            printf("**********************************\n");
            printf("The value of the first node is: %d, and it is deleted\n", newNode->data);
            printf("**********************************\n");
        }
        if(selection == '8'){
            int data;
            Node* newNode;
            getLast(list, &data);
            printf("**********************************\n");
            printf("The value of the last node is: %d, and it is deleted\n", newNode->data);
            printf("**********************************\n");
        }
        switch (selection)
        {
            case '3':
                printf("Enter the value you want to search: \n");
                scanf("%d", &data);
                break;
            case '4':
                printf("Enter the value you want to delete its node: \n");
                break;
            case '9':
                printf("**********************************\n");
                printf("The size of this list is: %d\n", getListLength(list));
                printf("**********************************\n");
                break;
            case 'p':
                printAllElements(list);
                break;
        default:
            break;
        }

    }while(selection != 'S' && selection != 's');

    deleteDLinkedList(list);

    return 0;
}