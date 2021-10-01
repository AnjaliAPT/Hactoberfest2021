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

node *top = NULL;

void push(int val)
{
    node *newnode = new node(val);
    newnode->data = val;
    newnode->next = top;
    top = newnode;
}

void pop()
{
    if (top == NULL)
    {
        cout << "Stack is empty" << endl;
    }
    else
    {
        cout << "The popped element is: " << top->data << endl;
        top = top->next;
    }
}

int Top()
{
    if (top == NULL)
    {
        cout << "Stack is empty" << endl;
    }
    else
    {
        return top->data;
    }
}

bool empty()
{
    return top == NULL;
}

void display()
{
    node *temp = top;
    if (top == NULL)
    {
        cout << "Stack is empty";
    }
    else
    {
        cout << "Stack elements are: ";
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
    cout << "0) Is Stack empty? " << endl;
    cout << "1) Push in stack" << endl;
    cout << "2) Pop from stack" << endl;
    cout << "3) Top element is" << endl;
    cout << "4) Display stack" << endl;
    cout << "5) Exit" << endl;
    do
    {
        cout << "Enter choice: ";
        cin >> ch;
        switch (ch)
        {
        case 0:
        {   
            if(top == NULL){

            cout << "Stack is empty!" << endl;
            }else{
                cout<<"Stack is not empty! "<< endl;
                display();
            }
            break;
        }
        case 1:
        {
            cout << "Enter value to be pushed: ";
            cin >> val;
            push(val);
            break;
        }
        case 2:
        {
            pop();
            break;
        }
        case 3:
        {
            int t = Top();
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