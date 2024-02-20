#include <stdio.h>
#include <string.h>
#include "StrList.h"
#include <stdlib.h>

/********************************************************************************
 *
 * A StrList library.
 *
 * This library provides a StrList of STRINGS data structure.
 *
 * This library will fail in unpredictable ways when the system memory runs
 * out.
 *
 ********************************************************************************/

/*
 * StrList represents a StrList data structure.
 */
typedef struct _Node{
    char* data;
    Node* next;
}Node;

struct _StrList{
    Node *head;
    size_t size;
};
typedef struct _StrList StrList;

/*
 * Allocates a new empty StrList.
 * It's the user responsibility to free it with StrList_free.
 */
StrList* StrList_alloc()
{
    StrList *slist = (StrList*)malloc(sizeof(StrList));
    if (slist == NULL)
    {
        exit(1);
    }
    return slist;

}

/*
 * Frees the memory and resources allocated to StrList.
 * If StrList==NULL does nothing (same as free).
 */
void StrList_free(StrList* StrList)
{
    Node* current = StrList->head;
    Node* next;
    while (current != NULL)
    {
        next = current->next;
        free(current->data);
        free(current);
        current = next;
    }
    free(StrList);
}

/*
 * Returns the number of elements in the StrList.
 */
size_t StrList_size(const StrList* StrList)
{
    return StrList->size;
}

/*
 * Inserts an element in the end of the StrList.
 */
void StrList_insertLast(StrList* StrList, const char* data)
{
    Node* newnode = (Node*)malloc(sizeof(Node));
    if (newnode == NULL)
    {
        exit(1);
    }
    newnode->data = (char*)malloc(strlen(data));
    Node* last = StrList->head;
    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = newnode;
    StrList->size++;
    
    
}

/*
* Inserts an element at given index
*/
void StrList_insertAt(StrList* StrList, const char* data,int index)
{
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->data = data;
    Node* current = StrList->head;
    if(index <= StrList->size)
    {
        for (int i = 0; i < index; i++)
        {
            current = current->next;
        } 
        newnode->next = current->next;
        current->next = newnode;
        StrList->size++;
    }
}

/*
 * Returns the StrList first data.
 */
char* StrList_firstData(const StrList* StrList)
{
    return StrList->head->data;
}

/*
 * Prints the StrList to the standard output.
 */
void StrList_print(const StrList* StrList)
{
    Node* current = StrList->head;
    while (current != NULL)
    {
        printf("%s\n", current->data);
        current = current->next;
    }

}

/*
 Prints the word at the given index to the standard output.
*/
void StrList_printAt(const StrList* Strlist,int index)
{
    Node* current = Strlist->head;
    for (int i = 0; i < index; i++)
    {
        current = current->next;
    }
    printf("%s\n", current->data);

}

/*
 * Return the amount of chars in the list.
*/
int StrList_printLen(const StrList* Strlist){
    int len = 0;
    Node* current = Strlist->head;
    while (current != NULL)
    {
        len += strlen(current->data);
        current = current->next;
    }
    return len;

}

/*
Given a string, return the number of times it exists in the list.
*/
int StrList_count(StrList* StrList, const char* data){
    int count = 0;
    Node* current = StrList->head;
    while (current != NULL)
    {
        if (strcmp(current->data, data) == 0)
        {
            count++;
        }
        current = current->next;
    }
    return count;
}

/*
	Given a string and a list, remove all the appearences of this string in the list.
*/
void StrList_remove(StrList* StrList, const char* data){
    Node* current = StrList->head;
    Node* prev = NULL;
    while(current != NULL){
        if(strcmp(current->data , data) == 0){
            prev->next = current->next;
            free(current->data);
            free(current);
            current = prev->next;
            continue;
            StrList->size--;
        }
        prev = current;
        current = current->next;
    }
}

/*
	Given an index and a list, remove the string at that index.
*/
void StrList_removeAt(StrList* StrList, int index){
    Node* current = StrList->head;
    Node* prev = NULL;
    Node* temp = NULL;
    for(int i=index; i>0; i--){
        prev = current;
        current = current->next;
    }

    prev->next = current->next;
    free(current->data);
    free(current);
    current = prev->next;
    StrList->size--;
    
}

/*
 * Checks if two StrLists have the same elements
 * returns 0 if not and any other number if yes
 */
int StrList_isEqual(const StrList* StrList1, const StrList* StrList2){
    Node* current1 = StrList1->head;
    Node* current2 = StrList2->head;

    while(current1 != NULL && current2 != NULL){
        if(strcmp(current1->data, current2->data) != 0){
            return 0;
        }
        current1 = current1->next;
        current2 = current2->next;
    }
    if(current1 == NULL && current2 == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

/*
 * Clones the given StrList. 
 * It's the user responsibility to free it with StrList_free.
 */
StrList* StrList_clone(const StrList* strList){
    StrList* newlist = StrList_alloc();
    Node* current = strList->head;
    
    while (strList != NULL)
    {
        Node* nnode = (Node*)malloc(sizeof(current));
        strcpy(nnode->data, current->data);
        StrList_insertLast(newlist, nnode->data);
        
    }
    return newlist;
    
    
}

/*
 * Reverces the given StrList. 
 */
void StrList_reverse( StrList* StrList)
{
    Node* prev = NULL;
    Node* current = StrList->head;
    Node* next = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    StrList->head = prev;
}

/*
 * Sort the given list in lexicographical order 
 */
void StrList_sort( StrList* StrList){
    Node* current = StrList->head;
    Node* next_node = StrList->head->next;
    Node* temp = NULL;
    Node* prev = NULL;

    while(current->next != NULL){
        prev = current;
        if(strcmp(current->data , current->next->data) > 0){
            temp = current;
            current->next = next_node->next;
            next_node = temp->next;
            prev->next = current;
            continue;
        }
        current = current->next;
        next_node = next_node->next;
    }

}

/*
 * Checks if the given list is sorted in lexicographical order
 * returns 1 for sorted,   0 otherwise
 */
int StrList_isSorted(StrList* StrList){
    Node* current = StrList->head;
    Node* next_node = StrList->head->next;
    while(current->next != NULL){
        if(strcmp(current->data , current->next->data) > 0){
            return 0;
        }
        current = current->next;
        next_node = next_node->next;
    }
}

