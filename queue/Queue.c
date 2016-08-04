#include "Queue.h"

// Initialize the Queue
void QueueInit(queue_t* queue)
{
    queue->head = NULL;
    queue->tail = NULL;
}

// Prints the queue.
void PrintQueue(queue_t* queue)
{
    printf("Queue :\n");
    PrintHead(queue->head);
}

// Prints the queue using queue head.
void PrintHead(node* head)
{
    if (head != NULL)
    {
        printf("%d ", head->value);
        PrintHead(head->next);
    }
    else
    {
        printf("\n");
    }
}

// Enqueues item into queue. Insert at tail. Similar to inserting items at end of a doubly
// linked list.
void QueueEnqueue(queue_t* queue, int insert_value)
{
    node* new = (node*) malloc(sizeof(node));

    if (new != NULL)
    {
        new->value = insert_value;
        new->previous = queue->tail;
        new->next = NULL;
        if (queue->tail != NULL)
        {
            (queue->tail)->next = new;
        }
        queue->tail = new;
    }

    if (queue->head == NULL)
    {
        queue->head = queue->tail;
    }
}

// Dequeue items from queue. Remove from front. Similar to removing items from
// start of a doubly linked list.
void QueueDequeue(queue_t* queue)
{
    if (queue->head != NULL)
    {
        node* crawler = (queue->head)->next;
        free(queue->head);
        queue->head = crawler;
    }
    else
    {
        printf("Queue Empty \n");
    }

    if (queue->head == NULL)
    {
        queue->tail = queue->head;
    }
}

// Destroy the queue.
void DestroyQueue(queue_t* queue)
{
    if (queue->head->next != NULL)
    {
        DestroyHead(queue->head);
        free(queue->tail);
    }
    else
    {
        DestroyHead(queue->head);
    }
}

// Destroy the node.
void DestroyHead(node* del_node)
{
    if(del_node != NULL)
    {
        DestroyHead(del_node->next);
        free(del_node);
    }
}
