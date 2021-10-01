//AVL tree
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

int height(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int lh = height(root->left);
    int rh = height(root->right);
    max(lh, rh) + 1;
}



bool isBalanced(Node *root, int *height)
{ //time complexity is O(n) because of ptr height

    if (root == NULL)
    { //if no node is present or it will be marked as empty balanced tree
        return true;
    }
    int lh = 0, rh = 0;
    if (isBalanced(root->left, &lh) == false)
    {
        return false;
    }

    if (isBalanced(root->right, &rh) == false)
    {
        return false;
    }

    *height = max(lh, rh) + 1;
    if (abs(lh - rh) <= 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{

    Node *root2 = new Node(1);
    root2->left = new Node(2);
    root2->left->left = new Node(3);
    cout << "Printed in inorder format: " << endl;
    inorder(root2);
    cout << endl;
    int height = 0;
    if (isBalanced(root2, &height) == true)
    {
        cout << "Balanced Tree";
    }
    else
    {
        cout << "Unbalanced Tree";
    }
    return 0;
}