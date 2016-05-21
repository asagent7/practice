#include "Queue.h"

int main()
{
    node* head = NULL;
    node* tail = NULL;
    int choice;
    int value;
    do 
    {
        printf("Enter your choice :\n1. Enqueue\n2. Dequeue\n3. Quit\n");

        scanf("%d", &choice);

        switch(choice)
        {
            case(1): printf("Enter value to be enqueued:\n");
                     scanf("%d", &value);
                     printf("Queue :\n");
                     QueueEnqueue(&tail, value);
                     if (head == NULL)
                     {
                         head = tail;
                     }
                     PrintQueue(head);
                     break;
            case(2): QueueDequeue(&head);
                     if (head == NULL)
                     {
                         tail = head;
                     }
                     PrintQueue(head);
                     printf("Queue :\n");
                     PrintQueue(head);
                     break;
            case(3): printf("Quitting\n");
                     Destroy(head);
                     free(tail);
                     break;
            default: printf("Enter correct choice\n");
                     break;
        }

    }while(choice != 3);

    return 0;
}
