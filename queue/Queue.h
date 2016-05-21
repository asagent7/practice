#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node* next;
    struct node* previous;
}node;

void PrintQueue(node* head);

void QueueEnqueue(node** ptail, int insert_value);

void QueueDequeue(node** phead);

void Destroy(node* del_node);

#endif /* end of include guard: __QUEUE_H__ */
