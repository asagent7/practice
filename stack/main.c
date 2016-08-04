#include "Stack.h"

int main()
{
    stack_t stack;
    int choice;
    int value;

    StackInit(&stack);
    do
    {
        printf("Enter your choice :\n%d Push\n%d Pop\n%d Quit\n", 1, 2, 3);

        scanf("%d", &choice);

        switch(choice)
        {
            case(1): printf("Enter value to be pushed:\n");
                     scanf("%d", &value);
                     PushToStack(&stack, value);
                     PrintStack(&stack);
                     break;
            case(2): PopFromStack(&stack);
                     PrintStack(&stack);
                     break;
            case(3): printf("Quitting\n");
                     DestroyStack(&stack);
                     break;
            default: printf("Enter correct choice\n");
                     break;
        }

    }while(choice != 3);

    return 0;
}
