#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node Node;

struct Node 
{
  int val;
  Node *next, *prev;
};

Node *new_node(void);
Node *get_num(int *length, char *argv[]);
void printing(Node *head);
void pop(Node *head);
void push(Node *head, int *val);

int main(int argc, char *argv[])
{
    int length = argc - 2 - 2;
    int val1 = atoi(argv[length + 2]);
    int val2 = atoi(argv[length + 3]);

    Node *head = get_num(&length, argv);
    pop(head);
    pop(head);
    push(head, &val1);
    push(head, &val2);

    printing(head);
    return 0;
}

Node *get_num(int *length, char *argv[])
{
    Node *head, *curr, *prev;
    head = new_node();
    curr = head;
    curr->prev = NULL;

    for (int i = 0; i < *length; ++i)
    {
        prev = curr;
        curr->next = new_node();
        curr->val = atoi(argv[i + 2]);
        
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

void printing(Node *head)
{
    Node *curr;
    curr = head;
    while (curr->next)
    {
        printf("%d\n", curr->val);
        curr = curr->next;
    }
}

void pop(Node *head)
{
    Node *curr;
    curr = head;
    while (curr->next)
    {
        curr = curr->next;
    }
    curr->prev->next = NULL;
    free(curr);
}

void push(Node *head, int *val)
{
    Node *curr, *prev;
    curr = head;
    while (curr->next)
    {
        curr = curr->next;
    }
    prev = curr;

    curr->next = new_node();
    curr->val = *val;

    curr = curr->next;
    curr->prev = prev; 
}