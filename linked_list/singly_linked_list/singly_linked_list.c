#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node* ptr;
}node;

node* Create(int insert_value);
void Destroy(node* del_node);
void InsertStart(node** phead, int insert_value);
void PrintList(node* head);
void InsertEnd(node** phead, int insert_value);
void InsertSort(node** phead, int insert_value);
void DeleteNode(node** phead, int delete_value);

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
