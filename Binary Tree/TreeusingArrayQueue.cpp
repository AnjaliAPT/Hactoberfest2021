// Isme Tree ka class nahi hai
#include <iostream>
using namespace std;

class Node
{
public:
    Node *lchild;
    int data;
    Node *rchild;
};

class Queue
{
private:
    int size;
    int front;
    int rear;
    Node **Q; // [Node*]*: Pointer to [Pointer to Node]
public:
    Queue(int size)
    {
        this->size = size;
        front = rear = -1;
        Q = new Node *[size]; // OR Q=(Node**) new Node;
    }
    ~Queue()
    {
        delete[] Q; // Frees the blocks of memory allocated in the heap
    }
    bool isEmpty()
    {
        if (front == rear)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool isFull()
    {
        if (rear == size - 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void enqueue(Node *x);
    Node *dequeue();
};

void Queue::enqueue(Node *x)
{
    if (isFull())
    {
        cout << "Queue is Full\n";
    }
    else
    {
        rear++;
        Q[rear] = x;
    }
}

Node *Queue::dequeue()
{
    Node *x;
    if (isEmpty())
    {
        cout << "Queue is Empty\n";
        x = NULL;
    }
    else
    {
        front++;
        x = Q[front];
    }
    return x;
}

Node *root = new Node;

void CreateTree()
{
    Node *p, *t;
    int x;
    Queue q(100);

    cout << "Enter the root value\n";
    cin >> x;
    root->data = x;
    root->lchild = root->rchild = NULL;
    q.enqueue(root);

    while (!q.isEmpty())
    {
        p = q.dequeue();

        cout << "Enter left child value of " << p->data << endl;
        cin >> x;
        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            q.enqueue(t);
        }

        cout << "Enter right child value of " << p->data << endl;
        cin >> x;
        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            q.enqueue(t);
        }
    }
}

void preOrder(Node *p)
{
    if (p)
    {
        cout << p->data << " ";
        preOrder(p->lchild);
        preOrder(p->rchild);
    }
}

void inOrder(Node *p)
{
    if (p)
    {
        preOrder(p->lchild);
        cout <<p->data<<" ";
        preOrder(p->rchild);
    }
}

void postOrder(Node *p)
{
    if (p)
    {
        postOrder(p->lchild);
        postOrder(p->rchild);
        cout <<p->data<<" ";
    }
}

int main()
{
    CreateTree();

    preOrder(root);
    cout <<endl;

    inOrder(root);
    cout <<endl;

    postOrder(root);
    cout <<endl;
    return 0;
}
