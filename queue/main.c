#include "Queue.h"

int main()
{
    queue_t queue;
    QueueInit(&queue);
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
                     QueueEnqueue(&queue, value);
                     PrintQueue(&queue);
                     break;
            case(2): QueueDequeue(&queue);
                     PrintQueue(&queue);
                     break;
            case(3): printf("Quitting\n");
#ifndef STATIC
                     DestroyQueue(&queue);
#endif
                     break;
            default: printf("Enter correct choice\n");
                     break;
        }

    }while(choice != 3);

    return 0;
}
