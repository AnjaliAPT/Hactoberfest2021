#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node()
    {
        next = NULL;
    }
    node(int val)
    {
        data = val;
        next = NULL;
    }
};

int getlength(node *&head)
{
    int count = 0;
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
        count++;
    }
    return (count + 1);
}

node *head = NULL;
node *tail = NULL;
void create(int val)
{
    //node *n = new node(val);

    node *temp = new node(val);
    temp->data = val;
    temp->next = NULL;

    if (head == NULL)
    {
        head = temp;
        tail = temp;
    }
    else
    {

        tail->next = temp;
        tail = tail->next;
    }
}

void insertAtHead(int val)
{
    node *n = new node();
    n->data = val;
    n->next = head;
    head = n;
}

void insertAtTail(node *&head, int val)
{
    node *n = new node(val);
    if (head == NULL)
    {
        head = n;
        return;
    }
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}

void insertAtPos(int newElement, int position)
{
    int count = getlength(head);
    node *newnode = new node(newElement);
    newnode->data = newElement;
    newnode->next = NULL;

    if (position < 1 || position > count)
    {
        cout << "\n Invalid position!" << endl;
    }
    else if (position == 1)
    {
        newnode->next = head;
        head = newnode;
    }
    else
    {
        node *temp = head;
        for (int i = 0; i < position - 1; i++)
        {
            if (temp != NULL)
            {
                temp = temp->next;
            }
        }
        if (temp != NULL)
        {
            newnode->next = temp->next;
            temp->next = newnode;
        }
        else
        {
            cout << "\nThe previous node is null";
        }
    }
}

void deleteAtHead(node *&head)
{
    //if list is empty.
    if (head == NULL)
        cout << "LIST IS EMPTY\n";
    else
    {
        node *ptr = head;
        head = head->next;
        free(ptr);
    }
}

void deleteAtpos(node *&head, int pos)
{
    int i = 1;
    node *temp = head, *nextnode;
    int count = getlength(head);
    if (pos < 1 || pos > count)
    {
        cout << "Invalid position!" << endl;
    }
    else if (pos == 1)
    {
        deleteAtHead(head);
    }
    else
    {
        while (i < pos - 1)
        {
            temp = temp->next;
            i++;
        }
        nextnode = temp->next;
        temp->next = nextnode->next;
        free(nextnode);
    }
}

node *reversek(node *&head, int k)
{
    node *prev = NULL;
    node *curr = head;
    node *next;
    int count = 0;
    while (curr != NULL && count < k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    if (next != NULL)
    {
        head->next = reversek(next, k);
    }

    return prev;
}

void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void deletion()
{

    node *ptr;

    //if list is empty.
    if (head == NULL)
        cout << "EMPTY LIST\n";
    //if list has only one node.
    if (head->next == NULL)
    {
        ptr = head;
        head = NULL;
        free(ptr);
    }
    //Traversing the list.
    else
    {
        node *prev;
        ptr = head;
        while (ptr->next != NULL)
        {
            prev = ptr;
            ptr = ptr->next;
        }
        prev->next = NULL;
        free(ptr);
    }
}

int main()
{
    node *head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    insertAtTail(head, 6);
    display(head);
    int k = 3;
    node *newhead = reversek(head, k);
    display(newhead);

    // create(1);
    // create(2);
    // create(3);
    // create(4);
    // cout << "Singly linked list created: ";
    // display(head);

    // insertAtHead(5);
    // cout << "Added node at Head: ";
    // display(head);
    // insertAtTail(head, 6);
    // cout << "Node inserted at Tail: ";
    // display(head);
    // insertAtPos(10, 2);
    // cout << "Insertion  of node at specific position: ";
    // display(head);
    // deletion(); //deleting the node from end
    // cout << "Node deleted from end: ";
    // display(head);
    // deleteAtHead(head);
    // cout << "Node at head deleted: ";
    // display(head);
    // deleteAtpos(head, 2);
    // cout << "Specific node deleted: ";
    // display(head);
    // int count = getlength(head);
    // cout << "Length of Singly linked list is: " << count;
    return 0;
}

//int position = 1;

//insertPos(10, 1);

// display(head);

// insertAtHead(1);
// insertAtTail(head, 5);
// insertAtTail(head, 6);
//insertPos(7,2);
//deleteAtpos(&head, position);
//display(head);
