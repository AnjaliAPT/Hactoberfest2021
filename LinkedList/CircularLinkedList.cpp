#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int val)
    {
        data = val;
        next = NULL;
    }
};

int getlength(node* &head) {
    int count = 0;
    node *temp=head;
    while(temp->next!=head){
        temp=temp->next;
        count++;
    }
    return (count+1);
}

void createCLL(node* &head, int val) {
    node * newnode = new node(val);
    node* temp;
    newnode->next=NULL;
    if(head == NULL){
        head=temp=newnode;
    }
    else{
        temp->next=newnode;
        temp=newnode;
    }
    temp->next=head;
}

void InsertAtHead(node *&head, int val)
{

    node *n = new node(val);
    node *temp = head;
    if (head == NULL)
    {
        n->next = n;
        head = n;
        return;
    }
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
    head = n;
}
void InsertAtTail(node *&head, int val)
{

    if (head == NULL)
    {
        InsertAtHead(head, val);
        return;
    }
    node *n = new node(val);
    node *temp = head;

    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
}

void insertAtPos(node *&head, int pos, int val) {
    node *newnode = new node(val);
    node* temp = head;
    int i=1, count = getlength(head);
    if(pos<1 || pos > count){
        cout<<"Invalid position!"<<endl;
    }
    else if(head == NULL){
        cout<<"List is empty!"<<endl;
    }
    else if(pos == 1){
        InsertAtHead(head, val);
        return;
    }
    else{
        newnode->next=NULL;
        temp=head;
        while(i<pos-1){
            temp=temp->next;
            i++;
        }
        newnode->next=temp->next;
        temp->next = newnode;
    }
}

void deleteAtHead(node *&head)
{
    node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    node *todelete = head;
    temp->next = head->next;
    head = head->next;

    delete todelete;
}

void deleteFromEnd(node* &head) {
    if (head != NULL)
    {

        //1. if head in not null and next of head
        //   is head, release the head
        if (head->next == head)
        {
            head = NULL;
        }
        else
        {

            //2. Else, traverse to the second last
            //   element of the list
            node *temp = head;
            while (temp->next->next != head)
                temp = temp->next;

            //3. Change the next of the second
            //   last node to head and delete the
            //   last node
            node *lastNode = temp->next;
            temp->next = head;
            free(lastNode);
        }
    }
}

void deletion(node *&head, int pos)  //delete node through specific position
{
    if (pos == 1)
    {
        deleteAtHead(head);
        return;
    }

    node *temp = head;
    int count = 1;

    while (count != pos - 1)
    {
        temp = temp->next;
        count++;
    }

    node *todelete = temp->next;
    temp->next = temp->next->next;
    delete todelete;
}

void display(node *head)
{
    node *temp = head;
    do
    {
        cout << temp->data << "->";
        temp = temp->next;
    } while (temp != head);
    cout << "NULL" << endl;
}

int main()
{
    node *head = NULL;
    // createCLL(head,6);
    // createCLL(head, 7);
    // createCLL(head, 8);
    // createCLL(head, 9);
    // cout<<"Create CLL: ";
    // display(head);
    // InsertAtTail(head, 1);
    // InsertAtTail(head, 2);
    // InsertAtTail(head, 3);
    // InsertAtTail(head, 4);
    // cout<<"InsertAtTail: ";
    // display(head);
   
    InsertAtHead(head, 8);
    InsertAtHead(head, 5);
    InsertAtHead(head, 9);
    InsertAtHead(head, 11);
    InsertAtHead(head, 20);
    cout<<"InsertAtHead: ";
    display(head);
    // insertAtPos(head, 5, 33);
    // cout << "InsertAtPos: ";
    // display(head);
    deletion(head, 4);
    cout<<"Delete the node from specific position: ";
    display(head);
    // deleteAtHead(head);
    // cout<<"Head deleted: ";
    // display(head);
    // deleteFromEnd(head);
    // cout<<"Deleted the  node from end: ";
    // display(head);
    // int count = getlength(head);
    // cout<<"Length of Circular Linked List is: "<<count;
    return 0;
}