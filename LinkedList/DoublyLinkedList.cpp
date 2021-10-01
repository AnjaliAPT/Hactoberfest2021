#include<iostream>
using namespace std;

class node{

    public:
    int data;
    node* next;
    node* prev;

    node(int val){
        data= val;
        next=NULL;
        prev=NULL;
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
    return (count+1);
}

node *tail;
void createDLL(node *&head, int newdata)
{
    node *newnode = new node(newdata);
    newnode->prev=NULL;
    newnode->next = NULL;
    if(head==NULL) {
        head=tail=newnode;
    }
    else{
        tail->next=newnode;
        newnode->prev=tail;
        tail=newnode;
    }
}

void insertAtHead(node* &head, int val){

    node* n=new node(val);
    n->next=head;
    if(head!=NULL){
        head->prev=n;
    }

    head=n;
}


void insertAtTail(node* &head, int val){

    if(head==NULL){
        insertAtHead(head,val);{
            return;
        }
    }

    node* n=new node(val);
    node* temp=head;

    while(temp->next!=NULL){
        temp=temp->next;
    }

    temp->next=n;
    n->prev=temp;
}


void insertAtPos(node* &head, int val, int pos){
    int i =1;
    if (head == NULL)
    {
        insertAtHead(head, val);
        {
            return;
        }
    }
    node *n = new node(val);
    node *temp = head;
    while (i<pos-1)
    {
        temp = temp->next;
        i++;
    }
    n->prev=temp;
    n->next=temp->next;
    temp->next=n;
    temp->next->prev=n;

}



void deleteAtHead(node* &head){

    node* todelete=head;
    head=head->next;
    head->prev=NULL;

    delete todelete;
}
void deletion(node* &head, int pos){   //deletion from anywhere

    if(pos==1){
        deleteAtHead(head);
        return;
    }

    node* temp=head;
    int count=1;

    while(temp!=NULL && count!=pos){
        temp=temp->next;
        count++;
    }

    temp->prev->next=temp->next;
    if(temp->next!=NULL){
        temp->next->prev=temp->prev;
    }

    delete temp;
}

void deletefromend(node* &head){
    if (head != NULL)
    {

        //1. if head in not null and next of head
        //   is null, release the head
        if (head->next == NULL)
        {
            head = NULL;
        }
        else
        {

            //2. Else, traverse to the second last
            //   element of the list
            node *temp = head;
            while (temp->next->next != NULL)
                temp = temp->next;

            //3. Change the next of the second
            //   last node to null and delete the
            //   last node
            node *lastNode = temp->next;
            temp->next = NULL;
            free(lastNode);
        }
    }
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

int length(node* head){

    int l=0;
    node* temp=head;
    while(temp!=NULL){
        l++;
        temp=temp->next;
    }
    return l;
}

int intersection(node* &head1, node* &head2){

    int l1=length(head1);
    int l2=length(head2);

    int d= 0;
    node* ptr1;
    node* ptr2;
    if(l1>l2){
        d=l1-l2;
        ptr1=head1;
        ptr2=head2;
    }
    else{
        d=l2-l1;
        ptr1=head2;
        ptr2=head1;
    }

    while(d){
        ptr1=ptr1->next;
        if(ptr1==NULL){
            return -1;
        }
        d--;
    }

    while(ptr1!=NULL && ptr2!=NULL){
        if(ptr1==ptr2){
            return ptr1->data;
        }
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }

    return -1;
}

int main()
{
    node* head=NULL;
    createDLL(head,1);
    createDLL(head, 2);
    createDLL(head, 3);
    cout<<"DLL created: ";
    display(head);
    insertAtTail(head,4);
    insertAtTail(head,5);
    insertAtTail(head,6);
    insertAtTail(head,7);
    cout<<"InsertAtTail : ";
    display(head);
    insertAtHead(head,0);
    cout<<"InsertionAtHead : ";
    display(head);
    deletion(head,3); //deleting as per given position
    cout<<"Delete any node : ";
    display(head);
    deleteAtHead(head);
    cout<<"DeleteAtHead : ";
    display(head);
    insertAtPos(head,23,3);
    cout<<"InsertAtPos : ";
    display(head);
    deletefromend(head);
    cout<<"Deletefromend : ";
    display(head);
    int count = getlength(head);
    cout<<"Length of Doubly linked list is: "<<count;
    
    return 0;
}