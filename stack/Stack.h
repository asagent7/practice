#ifndef __STACK_H__
#define __STACK_H__

#include <stdio.h>
#include <stdlib.h>

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

#endif /* end of include guard: __STACK_H__ */
