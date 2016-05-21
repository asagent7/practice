#include "DoublyLinkedList.h"

node* Create(int insert_value)
{
    node* new = (node*) malloc(sizeof(node));

    if (new != NULL)
    {
        new->value = insert_value;
        new->next = NULL;
        new->previous = NULL;
        return new;
    }
    else
    {
        return NULL;
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

void InsertStart(node** phead, int insert_value)
{
    node* new = (node*) malloc(sizeof(node));

    if (new != NULL)
    {
        new->value = insert_value;
        new->next = *phead;
        new->previous = NULL;
        *phead = new;
    }
}

void InsertEnd(node** phead, int insert_value)
{
    node* crawler;
    crawler = *phead;
    while (crawler->next != NULL)
    {
        crawler = crawler->next;
    }

    node* new = (node*) malloc(sizeof(node));

    if (new != NULL)
    {
        new->value = insert_value;
        new->next = NULL;
        new->previous = crawler;
        crawler->next = new;
    }
}

void InsertSort(node** phead, int insert_value)
{
    node* new;
    node* crawler = *phead;

    new = (node*) malloc(sizeof(node));
    new->value = insert_value;

    if (crawler != NULL)
    {
        while (crawler->value < insert_value && crawler->next != NULL)
        {
            crawler = crawler->next;
        }

        if (crawler->value < insert_value)
        {
            new->previous = crawler;
            new->next = NULL;
            crawler->next = new;
        }
        else
        {
            new->previous = crawler->previous;
            new->next = crawler;
            if(crawler->previous == NULL)
            {
                *phead = new;
            }
            else
            {
                crawler->previous->next = new;
            }
            crawler->previous = new;
        }
    }
    else
    {
        new->next = NULL;
        new->previous = NULL;
        *phead = new;
    }
}

void DeleteNode(node** phead, int delete_value)
{
    node* crawler = *phead;

    if (crawler != NULL)
    {
        while(crawler->value != delete_value)
        {
            crawler = crawler->next;
            if (crawler == NULL)
            {
                break;
            }
        }

        if (crawler != NULL)
        {
            if(!(crawler->previous == NULL && crawler->next == NULL))
            {
                if (crawler->previous == NULL)
                {
                    *phead = crawler->next;
                    crawler->next->previous = crawler->previous;
                }
                else if (crawler->next == NULL)
                {
                    crawler->previous->next = crawler->next;
                }
                else
                {
                    crawler->previous->next = crawler->next;
                    crawler->next->previous = crawler->previous;
                }
            }
            else
            {
                *phead = NULL;
            }
            free(crawler);
        }
        else
        {
            printf("No such node\n");
        }
    }
    else
    {
        printf("No such node\n");
    }
}

void PrintList(node* head)
{
    if (head != NULL)
    {
        printf("%d ", head->value);
        PrintList(head->next);
    }
    else
    {
        printf("\n");
    }
}
