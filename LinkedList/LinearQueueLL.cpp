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

node *front = NULL;
node *rear = NULL;

void enqueue(int val)
{
    node *newnode = new node(val);
    newnode->data = val;
    newnode->next = NULL;

    if (front == NULL && rear == NULL)
    {
        front = rear = newnode;
    }
    else if (rear != NULL)
    {
        rear->next = newnode;
        rear = newnode;
    }
}

void dequeue()
{
    node *temp;
    temp = front;
    if (front == NULL)
    {
        cout << "Queue is empty" << endl;
    }
    else
    {
        cout << "Element removed from Queue is: " << front->data << endl;
        front = front->next;
        free(temp);
    }
}

int peek()
{
    if (front != NULL)
    {
        return front->data;
    }
    return -1;
}

bool empty()
{
    return (front == NULL, rear == NULL);
}

void display()
{
    node *temp;
    if (front == NULL || rear == NULL)
    {
        cout << "Queue is empty";
    }
    else
    {
        temp = front;
        cout << "Queue elements are: ";
        while (temp != 0)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
    cout << endl;
}

int main()
{
    int ch, val;
    cout << "0) Is Queue empty? " << endl;
    cout << "1) Enqueue" << endl;
    cout << "2) Dequeue" << endl;
    cout << "3) Peek element is" << endl;
    cout << "4) Display Queue" << endl;
    cout << "5) Exit" << endl;
    do
    {
        cout << "Enter choice: ";
        cin >> ch;
        switch (ch)
        {
        case 0:
        {
            if (front == NULL && rear == NULL)
            {

                cout << "Queue is empty!" << endl;
            }
            else
            {
                cout << "Queue is not empty! " << endl;
                display();
            }
            break;
        }
        case 1:
        {
            cout << "Enter value to be pushed: ";
            cin >> val;
            enqueue(val);
            break;
        }
        case 2:
        {
            dequeue();
            break;
        }
        case 3:
        {
            int t = peek();
            cout << "Top element is: " << t << endl;
            break;
        }
        case 4:
        {
            display();
            break;
        }
        case 5:
        {
            cout << "Exit" << endl;
            break;
        }
        defalut:
        {
            cout << "Invalid choice" << endl;
        }
        }

    } while (ch != 5);
    return 0;
}