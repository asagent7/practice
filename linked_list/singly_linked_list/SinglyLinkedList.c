#include "SinglyLinkedList.h"

// Creates a new node with the insert value. Similar to insert in a blank list.
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

// Delete nodes recursively.
void Destroy(node* del_node)
{
    if(del_node != NULL)
    {
        Destroy(del_node->ptr);
        free(del_node);
    }
}

// Insert node at start of a list. Works with blank list also.
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

// Insert node at end of list. Works with blank list also.
void InsertEnd(node** phead, int insert_value)
{
    node* crawler;
    crawler = *phead;

    // Crawler searches till it hits the end of the list.
    while (crawler->ptr != NULL)
    {
        crawler = crawler->ptr;
    }

    // Create and insert node.
    node* new = (node*) malloc(sizeof(node));

    if (new != NULL)
    {
        new->value = insert_value;
        new->ptr = NULL;
        crawler->ptr = new;
    }
}

// Inserts in the list in a sorted order.
void InsertSort(node** phead, int insert_value)
{
    node* new;
    node* crawler = *phead;
    node* precrawler = NULL;

    // Check if head is NULL, meaning blank list.
    if (crawler != NULL)
    {
        // Search till last node is reached or crawler reaches a node whose
        // value is greater than the value to be inserted.
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

    // Create node.
    new = (node*) malloc(sizeof(node));
    new->value = insert_value;

    // If inserting at start.
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

// Deletes the node corresponding to the value.
void DeleteNode(node** phead, int delete_value)
{
    node* crawler = *phead;
    node* precrawler = NULL;

    // Check if list is blank.
    if (crawler != NULL)
    {
        // Search till crawler reaches the correct node or the end.
        while(crawler->value != delete_value)
        {
            precrawler = crawler;
            crawler = crawler->ptr;
            if (crawler == NULL)
            {
                break;
            }
        }

        // Check if last node is reached.
        if (crawler != NULL)
        {
            // If first node of list.
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

// Prints the list.
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
