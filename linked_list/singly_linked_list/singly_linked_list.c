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
    insert_sort(&head, 5);
    if (head != NULL)
    {
        print_list(head);
        printf("Inserting new value...\n");
        insert_sort(&head, 6);
        print_list(head);
        printf("Inserting new value...\n");
        insert_sort(&head, 4);
        print_list(head);
        //printf("Inserting new value...\n");
        //insert_sort(&head, 6);
        //print_list(head);
        printf("Deleting value 6...\n");
        delete_node(&head, 6);
        print_list(head);
        destroy(head);
        return 0;
    }
    else
    {
        return 1;
    }

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
