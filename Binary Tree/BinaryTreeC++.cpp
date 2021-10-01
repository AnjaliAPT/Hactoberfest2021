#include <iostream>
#include "QueueCpp.h" // Header file
using namespace std;

class Tree
{
    private:
      Node *root;
    public:
      Tree()
      {
          root = NULL;
      }
      void Create();
      void preOrder()
      {
          preOrder(root);
      }
      void preOrder(Node *p);
      void inOrder()
      {
          inOrder(root);
      }
      void inOrder(Node *p);
      void postOrder()
      {
          postOrder(root);
      }
      void postOrder(Node *p);
      void levelOrder()
      {
          levelOrder(root);
      }
      void levelOrder(Node *p);
      int Height()
      {
          return Height(root);
      }
      int Height(Node *root);
};

void Tree::Create()
{
    Node *p, *t;
    int x;
    Queue q(100);
    cout <<"Enter the value of Root\n";
    cin >>x;
    root = new Node;
    root->data=x;
    q.enqueue(root);

    while (!q.isEmpty())
    {
        p = q.dequeue();
        cout <<"Enter Left child of "<<p->data<<endl;
        cin >>x;
        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            q.enqueue(t);
        }
        cout <<"Enter Right child of "<<p->data<<endl;
        cin >>x;
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

void Tree::preOrder(Node *p)
{
    if (p)
    {
        cout <<p->data<<" ";
        preOrder(p->lchild);
        preOrder(p->rchild);
    }
}

void Tree::inOrder(Node *p)
{
    if (p)
    {
        inOrder(p->lchild);
        cout <<p->data<<" ";
        inOrder(p->rchild);
    }
}

void Tree::postOrder(Node *p)
{
    if (p)
    {
        postOrder(p->lchild);
        postOrder(p->rchild);
        cout <<p->data<<" ";
    }
}

void Tree::levelOrder(Node *root) // Prints the value of the node of the tree in Level by Level Order
{
    Queue q(100);
    cout <<root->data<<" ";
    q.enqueue(root);

    while (!q.isEmpty())
    {
        root = q.dequeue();
        if (root->lchild)
        {
            cout <<root->lchild->data<<" ";
            q.enqueue(root->lchild);
        }
        if (root->rchild)
        {
            cout <<root->rchild->data<<" ";
            q.enqueue(root->rchild);
        }
    }   
}

int Tree::Height(Node *root)
{
    int x=0, y=0;
    if (root == 0)// Matlab agar root null hai
    {
        return 0;
    }
    x = Height(root->lchild);
    y = Height(root->rchild);

    if (x > y)
    {
        return x+1;
    }
    else
    {
        return y+1;
    }
}

int main()
{
    Tree t;
    t.Create();
    cout <<"preOrder: ";
    t.preOrder();
    cout <<endl;
    cout <<"inOrder:  ";
    t.inOrder();
    cout <<endl;
    cout <<"postOrder: ";
    t.postOrder();
    cout <<endl;
    cout <<t.Height();
    return 0;
}
