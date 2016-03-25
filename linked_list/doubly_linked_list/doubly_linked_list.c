#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node* previous;
    struct node* next;
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
        insert_sort(&head, 8);
        print_list(head);
        printf("Inserting new value...\n");
        insert_sort(&head, 4);
        print_list(head);
        printf("Inserting new value...\n");
        insert_sort(&head, 6);
        print_list(head);
        printf("Deleting value 6...\n");
        delete_node(&head, 4);
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
        new->next = NULL;
        new->previous = NULL;
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
        destroy(del_node->next);
        free(del_node);
    }
}

void insert_start(node** head, int insert_value)
{
    node* new = (node*) malloc(sizeof(node));

    if (new != NULL)
    {
        new->value = insert_value;
        new->next = *head;
        new->previous = NULL;
        *head = new;
    }
}

void insert_end(node** head, int insert_value)
{
    node* crawler;
    crawler = *head;
    while (crawler->next != NULL)
    {
        crawler = crawler->next;
    }

    node* new = (node*) malloc(sizeof(node));

    if (new != NULL)
    {
        new->value = insert_value;
        new->next = NULL;
        new->previous = crawler;
        crawler->next = new;
    }
}

void insert_sort(node** head, int insert_value)
{
    node* new;
    node* crawler = *head;

    if (crawler != NULL)
    {
        while (crawler->value < insert_value && crawler->next != NULL)
        {
            crawler = crawler->next;
        }

        if (crawler->value < insert_value)
        {
            new = (node*) malloc(sizeof(node));
            new->value = insert_value;
            new->previous = crawler;
            new->next = NULL;
            crawler->next = new;
        }
        else
        {
            new = (node*) malloc(sizeof(node));
            new->value = insert_value;
            new->previous = crawler->previous;
            new->next = crawler;
            if(crawler->previous == NULL)
            {
                *head = new;
            }
            else
            {
                crawler->previous->next = new;
                crawler->previous = new;
            }
        }
    }
    else
    {
        new = (node*) malloc(sizeof(node));
        new->value = insert_value;
        new->next = NULL;   // NULL
        new->previous = NULL;
        *head = new;
    }

}

void delete_node(node** head, int delete_value)
{
    node* crawler = *head;

    if (crawler != NULL)
    {
        while(crawler->value != delete_value)
        {
            crawler = crawler->next;
            if (crawler == NULL)
            {
                break;
            }
        }

        if (crawler != NULL)
        {
            if (crawler->previous == NULL)
            {
                *head = crawler->next;
            }
            else if (crawler->next == NULL)
            {
                crawler->previous->next = crawler->next;
            }
            else
            {
                crawler->previous->next = crawler->next;
                crawler->next->previous = crawler->previous;
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
        print_list(head->next);
    }
    else
    {
        printf("\n");
    }
}
