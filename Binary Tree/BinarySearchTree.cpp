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

Node *searchInBST(Node *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == key)
    {
        return root;
    }
    //data > key
    if (root->data > key)
    {
        return searchInBST(root->left, key);
    }
    //data < key
    return searchInBST(root->right, key);
}

Node *insertBST(Node *root, int val)
{
    if (root == NULL)
    {
        return new Node(val);
    }
    if (val < root->data)
    {
        root->left = insertBST(root->left, val);
    }
    else
    {
        //val>root->data
        root->right = insertBST(root->right, val);
    }
    return root;
}

Node *inorderSucc(Node *root) //inorderSuccessor is the value which is coming after the value which is to be deleted
{
    Node *curr = root;
    while (curr && curr->left != NULL)
    {
        curr = curr->left;
    }
    return curr;
}

Node *deleteInBST(Node *root, int key)
{
    if (key < root->data)
    {
        root->left = deleteInBST(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = deleteInBST(root->right, key);
    }
    else
    {
        if (root->left == NULL)
        {
            Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            free(root);
            return temp;
        }
        //case 3
        Node *temp = inorderSucc(root->right);
        root->data = temp->data;
        root->right = deleteInBST(root->right, temp->data);
    }
    return root;
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
    Node *root = NULL;
    root = insertBST(root, 5);
    insertBST(root, 1);
    insertBST(root, 3);
    insertBST(root, 4);
    insertBST(root, 2);
    insertBST(root, 7);
    // if (searchInBST(root, 10) == NULL)
    // {
    //     cout << "Key does not exist." << endl;
    // }
    // else
    // {
    //     cout << "Key exists" << endl;
    // }
    cout << "Printed in inorder format: " << endl;
    inorder(root);
    cout << endl;
    // cout << "Node deleted" << endl;
    root = deleteInBST(root, 7);
    cout << "Printed in inorder format after deleting node : " << endl;
    inorder(root);
    return 0;
}

//BST's inorder results are sorted.
//Time  complexity for BST: O(logn) for best  case otherwise it is O(n)
//Time complexity for general Binary Tree: O(n)