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

typedef struct _queue_t
{
    node* head;
    node* tail;
} queue_t;

void QueueInit(queue_t* queue);

void PrintHead(node* head);

void PrintQueue(queue_t* queue);

void QueueEnqueue(queue_t* queue, int insert_value);

void QueueDequeue(queue_t* queue);

void DestroyQueue(queue_t* queue);

void DestroyHead(node* head);

#endif /* end of include guard: __QUEUE_H__ */
