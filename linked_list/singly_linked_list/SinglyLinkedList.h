#ifndef __SINGLYLINKEDLIST_H__
#define __SINGLYLINKEDLIST_H__

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

#endif /* end of include guard: __SINGLYLINKEDLIST_H__ */
