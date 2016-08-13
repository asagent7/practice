#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <stdio.h>
#include <stdlib.h>

#ifndef STATIC

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

#else

#define QUEUE_CAPACITY 64

typedef struct _queue_t
{
    int data[QUEUE_CAPACITY];
    int front;
    int size;
} queue_t;

void QueueInit(queue_t* queue);

void PrintQueue(queue_t* queue);

void QueueEnqueue(queue_t* queue, int insert_value);

void QueueDequeue(queue_t* queue);

#endif

#endif /* end of include guard: __QUEUE_H__ */
