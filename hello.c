// Program to implement doubly linked list

#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
}Node;

void print_node_forward(Node *n)
{
    printf("Printing the list in forward order:\n");

    while(n != NULL)
    {
        printf("%i ", n->data);
        n = n->next;
    }

    printf("\n");
}

void print_node_reverse(Node *n)
{
    printf("Printing the list in reverse order:\n");

    while(n->next != NULL) // Loop to get to the end of the list
    {
        n = n->next;
    }

    while(n != NULL) // Loop to print from the end of the list
    {
        printf("%i ", n->data);
        n = n->prev;
    }

    printf("\n");
}

void insert_node(Node *h, int data)
{
    Node *tempnode = malloc(sizeof *tempnode);
    tempnode->data = data;
    tempnode->next = NULL;

    while(h->next != NULL)
    {
        h = h->next;
    }

    h->next = tempnode;
    tempnode->prev = h;
}

int main(int argc, char const *argv[])
{

    int n;
    printf("Enter number of nodes: \n");
    scanf("%i", &n);

    if (n <= 0)
    {
        return 0;
    }

    Node *head = malloc(sizeof *head);
    head->next = NULL;
    head->prev = NULL;

    for (int i = 0; i < n; ++i)
    {
        int temp;
        printf("Enter data for node %i: \n", i + 1);
        scanf("%i", &temp);

        if (i == 0)
        {
            head->data = temp;
        }
        else
            insert_node(head, temp);
    }

    print_node_forward(head);
    print_node_reverse(head);

    return 0;
}