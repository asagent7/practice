#include "Stack.h"

void PrintStack(node* head)
{
    if (head != NULL)
    {
        printf("%d ", head->value);
        PrintStack(head->next);
    }
    else
    {
        printf("\n");
    }
}

void PushToStack(node** ptop, int insert_value)
{
    node* new = (node*) malloc(sizeof(node));

    if (new != NULL)
    {
        new->value = insert_value;
        new->next = *ptop;
        *ptop = new;
    }
}

void PopFromStack(node** ptop)
{
    node* crawler = (*ptop)->next;
    
    free(*ptop);

    *ptop = crawler;
}

void Destroy(node* del_node)
{
    if(del_node != NULL)
    {
        Destroy(del_node->next);
        free(del_node);
    }
}
