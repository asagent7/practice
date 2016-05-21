#ifndef DOUBLY_LINKED_LIST_H_
#define DOUBLY_LINKED_LIST_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node* previous;
    struct node* next;
}node;

node* Create(int insert_value);

void Destroy(node* del_node);

void InsertStart(node** phead, int insert_value);

void PrintList(node* phead);

void InsertEnd(node** phead, int insert_value);

void InsertSort(node** phead, int insert_value);

void DeleteNode(node** phead, int delete_value);


#endif /* end of include guard: DOUBLY_LINKED_LIST_H_ */
