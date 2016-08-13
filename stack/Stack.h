#ifndef __STACK_H__
#define __STACK_H__

#include <stdio.h>
#include <stdlib.h>

#ifndef STATIC

typedef struct node
{
    int value;
    struct node* next;
}node;

typedef struct _stack_t
{
    node* top;
} stack_t;

void StackInit(stack_t* stack);

void PrintTop(node* top);

void PrintStack(stack_t* stack);

void PushToStack(stack_t* stack, int insert_value);

void PopFromStack(stack_t* stack);

void DestroyStack(stack_t* stack);

void DestroyTop(node* del_node);

#else

#define STACK_CAPACITY  64
#define STACK_EMPTY     -1

typedef struct _stack_t
{
    int data[STACK_CAPACITY];
    int top;
} stack_t;

void StackInit(stack_t* stack);

void PrintStack(stack_t* stack);

void PushToStack(stack_t* stack, int insert_value);

void PopFromStack(stack_t* stack);

#endif /* ifdef STATIC */

#endif /* end of include guard: __STACK_H__ */
