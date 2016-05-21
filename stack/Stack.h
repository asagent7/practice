#ifndef __STACK_H__
#define __STACK_H__

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node* next;
}node;

void PrintStack(node* head);

void PushToStack(node** phead, int insert_value);

void PopFromStack(node** phead);

void Destroy(node* del_node);

#endif /* end of include guard: __STACK_H__ */
