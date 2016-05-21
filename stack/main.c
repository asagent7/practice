#include "Stack.h"

int main()
{
    node* top = NULL;
    int choice;
    int value;
    do 
    {
        printf("Enter your choice :\n%d Push\n%d Pop\n%d Quit\n", 1, 2, 3);

        scanf("%d", &choice);

        switch(choice)
        {
            case(1): printf("Enter value to be pushed:\n");
                     scanf("%d", &value);
                     PushToStack(&top, value);
                     printf("Stack :\n");
                     PrintStack(top);
                     break;
            case(2): PopFromStack(&top);
                     printf("Stack :\n");
                     PrintStack(top);
                     break;
            case(3): printf("Quitting\n");
                     Destroy(top);
                     break;
            default: printf("Enter correct choice\n");
                     break;
        }

    }while(choice != 3);

    return 0;
}
