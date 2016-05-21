#include "singly_linked_list.h"

node* Create(int insert_value)
{
    node* new = (node*) malloc(sizeof(node));

    if (new != NULL)
    {
        new->value = insert_value;
        new->ptr = NULL;
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
        Destroy(del_node->ptr);
        free(del_node);
    }
}

void InsertStart(node** phead, int insert_value)
{
    node* new = (node*) malloc(sizeof(node));

    if (new != NULL)
    {
        new->value = insert_value;
        new->ptr = *phead;
        *phead = new;
    }
}

void InsertEnd(node** phead, int insert_value)
{
    node* crawler;
    crawler = *phead;
    while (crawler->ptr != NULL)
    {
        crawler = crawler->ptr;
    }

    node* new = (node*) malloc(sizeof(node));

    if (new != NULL)
    {
        new->value = insert_value;
        new->ptr = NULL;
        crawler->ptr = new;
    }
}

void InsertSort(node** phead, int insert_value)
{
    node* new;
    node* crawler = *phead;
    node* precrawler = NULL;

    if (crawler != NULL)
    {
        while (crawler->value < insert_value)
        {
            precrawler = crawler;
            crawler = crawler->ptr;
            if(crawler == NULL)
            {
                break;
            }
        }
    }

    new = (node*) malloc(sizeof(node));
    new->value = insert_value;

    if(precrawler == NULL)
    {
        new->ptr = *phead;   // NULL
        *phead = new;
    }
    else
    {
        new->ptr = crawler;
        precrawler->ptr = new;
    }
}

void DeleteNode(node** phead, int delete_value)
{
    node* crawler = *phead;
    node* precrawler = NULL;

    if (crawler != NULL)
    {
        while(crawler->value != delete_value)
        {
            precrawler = crawler;
            crawler = crawler->ptr;
            if (crawler == NULL)
            {
                break;
            }
        }

        if (crawler != NULL)
        {
            if (precrawler == NULL)
            {
                *phead = crawler->ptr;
            }
            else
            {
                precrawler->ptr = crawler->ptr;
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
        PrintList(head->ptr);
    }
    else
    {
        printf("\n");
    }
}
