#include "DoublyLinkedList.h"

// Creates a new node with the insert value. Similar to insert in a blank list.
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

// Delete nodes recursively.
void Destroy(node* del_node)
{
    if(del_node != NULL)
    {
        Destroy(del_node->next);
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
        new->next = *phead;
        new->previous = NULL;
        if (*phead != NULL)
        {
            (*phead)->previous = new;
        }
        *phead = new;
    }
}

// Insert node at end of list. Works with blank list also.
void InsertEnd(node** phead, int insert_value)
{
    node* crawler;
    crawler = *phead;

    // Crawler searches till it hits the end of the list.
    while (crawler->next != NULL)
    {
        crawler = crawler->next;
    }

    // Create and insert node.
    node* new = (node*) malloc(sizeof(node));

    if (new != NULL)
    {
        new->value = insert_value;
        new->next = NULL;
        new->previous = crawler;
        crawler->next = new;
    }
}

// Inserts in the list in a sorted order.
void InsertSort(node** phead, int insert_value)
{
    node* new;
    node* crawler = *phead;

    // Create node.
    new = (node*) malloc(sizeof(node));
    new->value = insert_value;

    // Check if head is NULL, meaning blank list.
    if (crawler != NULL)
    {
        // Search till last node is reached or crawler reaches a node whose
        // value is greater than the value to be inserted.
        while (crawler->value < insert_value && crawler->next != NULL)
        {
            crawler = crawler->next;
        }

        // Check if the last node is reached and insert at end.
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

            // If inserting at start.
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

// Deletes the node corresponding to the value.
void DeleteNode(node** phead, int delete_value)
{
    node* crawler = *phead;

    // Check if list is blank.
    if (crawler != NULL)
    {
        // Search till crawler reaches the correct node or the end.
        while(crawler->value != delete_value)
        {
            crawler = crawler->next;
            if (crawler == NULL)
            {
                break;
            }
        }

        // Check if last node is reached.
        if (crawler != NULL)
        {
            // Check if node is not the only node in the list.
            if(!(crawler->previous == NULL && crawler->next == NULL))
            {
                // If first node of list.
                if (crawler->previous == NULL)
                {
                    *phead = crawler->next;
                    crawler->next->previous = crawler->previous;
                }
                // If last node of list.
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
            // If it is the only node in the list, point head to NULL.
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

// Prints the list.
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
