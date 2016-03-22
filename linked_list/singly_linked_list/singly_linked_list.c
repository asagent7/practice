#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node* ptr;
}node;

node* create(int insert_value);
void destroy(node* del_node);

int main()
{
    node* first = NULL;
    first = create(5);
    if (first != NULL)
    {
        printf("%d\n", first->value);
        destroy(first);
        return 0;
    }
    else
    {
        return 1;
    }

}

node* create(int insert_value)
{
    node* new = malloc(sizeof(node));

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
