#ifndef SINGLY_LINKED_LIST_H_
#define SINGLY_LINKED_LIST_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node* ptr;
}node;

node* Create(int insert_value);

void Destroy(node* del_node);

void InsertStart(node** phead, int insert_value);

void PrintList(node* head);

void InsertEnd(node** phead, int insert_value);

void InsertSort(node** phead, int insert_value);

void DeleteNode(node** phead, int delete_value);

#endif /* end of include guard: SINGLY_LINKED_LIST_H_ */
