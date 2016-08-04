#include "Stack.h"

// Initialize the stack.
void StackInit(stack_t* stack)
{
    stack->top = NULL;
}

// Prints the stack
void PrintStack(stack_t* stack)
{
    printf("Stack :\n");
    PrintTop(stack->top);
}

// Prints the nodes from the top
void PrintTop(node* top)
{
    if (top != NULL)
    {
        printf("%d ", top->value);
        PrintTop(top->next);
    }
    else
    {
        printf("\n");
    }
}

// Push to stack. Similar to inserting at start of linked list.
void PushToStack(stack_t* stack, int insert_value)
{
    node* new = (node*) malloc(sizeof(node));

    if (new != NULL)
    {
        new->value = insert_value;
        new->next = stack->top;
        stack->top = new;
    }
}

// Pop from stack. Similar to removing from start of linked list.
void PopFromStack(stack_t* stack)
{
    if (stack->top != NULL)
    {
        node* crawler = (stack->top)->next;
        free(stack->top);
        stack->top = crawler;
    }
}

// Destroy the stack.
void DestroyStack(stack_t* stack)
{
    DestroyTop(stack->top);
}

// Destroy the nodes recursively.
void DestroyTop(node* del_node)
{
    if(del_node != NULL)
    {
        DestroyTop(del_node->next);
        free(del_node);
    }
}
