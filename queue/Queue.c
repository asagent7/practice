#include "Queue.h"

void PrintQueue(node* head)
{
    if (head != NULL)
    {
        printf("%d ", head->value);
        PrintQueue(head->next);
    }
    else
    {
        printf("\n");
    }
}

void QueueEnqueue(node** ptail, int insert_value)
{
    node* new = (node*) malloc(sizeof(node));

    if (new != NULL)
    {
        new->value = insert_value;
        new->previous = *ptail;
        new->next = NULL;
        if (*ptail != NULL)
        {
            (*ptail)->next = new;
        }
        *ptail = new;
    }
}

void QueueDequeue(node** phead)
{
    if (*phead != NULL)
    {
        node* crawler = (*phead)->next;
        free(*phead);
        *phead = crawler;
    }
}

void Destroy(node* del_node)
{
    if(del_node != NULL)
    {
        Destroy(del_node->next);
        free(del_node);
    }
}
