#include <stdio.h>
#include <stdlib.h>

// Node
struct Node
{
    int data;
    struct Node *next;
};

// print a given linked list
void printList(struct Node *head)
{
    struct Node *ptr = head;
    while (ptr)
    {
        printf("%d —> ", ptr->data);
        ptr = ptr->next;
    }

    printf("NULL\n");
}

void push(struct Node **head, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;

    *head = newNode;
}

void recursiveReverse(struct Node *head, struct Node **headRef)
{
    struct Node *first;
    struct Node *rest;

    // empty list base case
    if (head == NULL)
    {
        return;
    }

    first = head;
    rest = first->next;

    // base case: the list has only one node
    if (rest == NULL)
    {
        *headRef = first;
        return;
    }

    recursiveReverse(rest, headRef);

    // put the first item at the end of the list
    rest->next = first;
    first->next = NULL;
}

void reverse(struct Node **head)
{
    recursiveReverse(*head, head);
}

int main(void)
{
    // input keys
    int keys[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(keys) / sizeof(keys[0]);

    struct Node *head = NULL;
    for (int i = n - 1; i >= 0; i--)
    {
        push(&head, keys[i]);
    }

    reverse(&head);
    printList(head);

    return 0;
}