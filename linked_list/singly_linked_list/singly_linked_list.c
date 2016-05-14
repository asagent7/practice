#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node* ptr;
}node;

node* create(int insert_value);
void destroy(node* del_node);
void insert_start(node** head, int insert_value);
void print_list(node* head);
void insert_end(node** head, int insert_value);
void insert_sort(node** head, int insert_value);
void delete_node(node** head, int delete_value);

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
                     insert_sort(&head, value);
                     printf("List :\n");
                     print_list(head);
                     break;
            case(2): printf("Enter value to be deleted:\n");
                     scanf("%d", &value);
                     delete_node(&head, value);
                     printf("List :\n");
                     print_list(head);
                     break;
            case(3): printf("Quitting\n");
                     destroy(head);
                     break;
            default: printf("Enter correct choice\n");
                     break;
        }

    }while(choice != 3);

    return 0;
}

node* create(int insert_value)
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

void destroy(node* del_node)
{
    if(del_node != NULL)
    {
        destroy(del_node->ptr);
        free(del_node);
    }
}

void insert_start(node** head, int insert_value)
{
    node* new = (node*) malloc(sizeof(node));

    if (new != NULL)
    {
        new->value = insert_value;
        new->ptr = *head;
        *head = new;
    }
}

void insert_end(node** head, int insert_value)
{
    node* crawler;
    crawler = *head;
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

void insert_sort(node** head, int insert_value)
{
    node* new;
    node* crawler = *head;
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

    if(precrawler == NULL)
    {
        new = (node*) malloc(sizeof(node));
        new->value = insert_value;
        new->ptr = *head;   // NULL
        *head = new;
    }
    else
    {
        new = (node*) malloc(sizeof(node));
        new->value = insert_value;
        new->ptr = crawler;
        precrawler->ptr = new;
    }
}

void delete_node(node** head, int delete_value)
{
    node* crawler = *head;
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
                *head = crawler->ptr;
            }
            else
            {
                precrawler->ptr = crawler->ptr;
            }
            free(crawler);
        }
    }
}

void print_list(node* head)
{
    if (head != NULL)
    {
        printf("%d ", head->value);
        print_list(head->ptr);
    }
    else
    {
        printf("\n");
    }
}
