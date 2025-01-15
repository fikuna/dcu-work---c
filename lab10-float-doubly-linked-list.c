#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node Node;

struct Node
{
    float val;
    Node *next, *prev;

};

Node *new_node(void);
Node *get_numbers(int *length, char *argv[]);
void print_num(int *length, Node *head);

int main(int argc, char *argv[])
{
    int length = argc - 2;
    Node *head = get_numbers(&length, argv);
    print_num(&length, head);

    return 0;

}

Node *get_numbers(int *length, char *argv[])
{
    Node *head, *curr, *prev;
    head = new_node();
    curr = head;
    curr->prev = NULL;
    for (int i = 0; i < *length; ++i)
    {
        prev = curr;
        curr->next = new_node();
        curr->val = atof(argv[i + 2]);

        curr = curr->next;
        curr->prev = prev;

    }
    curr->next = NULL;
    return head;

}

Node *new_node()
{
    Node *new = (Node *)calloc(1, sizeof(Node *));
    if (!new)
    {
    printf("Error allocating memory!\n");
    exit(0);
    }
    return new;
}

void print_num(int *length, Node *head)
{
    Node *curr;
    curr = head;
    while (curr->next)
    {
        curr = curr->next;

    }
    while (curr->prev)
    {
        curr = curr->prev;
        printf("%.2f\n", curr->val);
    }
}
