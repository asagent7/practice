#include "singly_linked_list.h"

int main()
{
    node* head = NULL;
    int choice;
    int value;
    do 
    {
        printf("Enter your choice :\n%d Insert\n%d Delete\n%d Quit\n", 1, 2, 3);

        scanf("%d", &choice);

        switch(choice)
        {
            case(1): printf("Enter value to be inserted:\n");
                     scanf("%d", &value);
                     InsertSort(&head, value);
                     printf("List :\n");
                     PrintList(head);
                     break;
            case(2): printf("Enter value to be deleted:\n");
                     scanf("%d", &value);
                     DeleteNode(&head, value);
                     printf("List :\n");
                     PrintList(head);
                     break;
            case(3): printf("Quitting\n");
                     Destroy(head);
                     break;
            default: printf("Enter correct choice\n");
                     break;
        }

    }while(choice != 3);

    return 0;
}
