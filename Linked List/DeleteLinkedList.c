#include <stdio.h>
#include <stdlib.h>

// Node
struct Node
{
    int data;
    struct Node *next;
};

void push(struct Node **head, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

// Function to delete a linked list
void deleteList(struct Node **head)
{
    struct Node *prev = *head;

    while (*head)
    {
        *head = (*head)->next;

        printf("Deleting %d\n", prev->data);
        free(prev);
        prev = *head;
    }
}

int main(void)
{
    // input keys
    int keys[] = {1, 2, 3, 4, 5};
    int n = sizeof(keys) / sizeof(keys[0]);

    // points to the head node of the linked list
    struct Node *head = NULL;

    // construct a linked list
    for (int i = n - 1; i >= 0; i--)
    {
        push(&head, keys[i]);
    }

    deleteList(&head);

    if (head == NULL)
    {
        printf("List deleted");
    }

    return 0;
}
