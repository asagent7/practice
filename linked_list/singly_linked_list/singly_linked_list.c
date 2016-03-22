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

int main()
{
    node* head = NULL;
    insert_start(&head, 5);
    if (head != NULL)
    {
        print_list(head);
        printf("Inserting new value...\n");
        insert_start(&head, 7);
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
