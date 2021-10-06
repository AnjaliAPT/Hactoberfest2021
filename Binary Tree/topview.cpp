
Top view of a binary tree is the set of nodes visible when the tree is viewed from the top. Given a binary tree, print the top view of it. The output nodes can be printed in any order.

A node x is there in output if x is the topmost node at its horizontal distance. Horizontal distance of left child of a node x is equal to horizontal distance of x minus 1, and that of right child is horizontal distance of x plus 1. 

       1
    /     \
   2       3
  /  \    / \
 4    5  6   7
Top view of the above binary tree is
4 2 1 3 7

        1
      /   \
    2       3
      \   
        4  
          \
            5
             \
               6
Top view of the above binary tree is
2 1 3 6
Recommended: Please solve it on “PRACTICE” first, before moving on to the solution.
The idea is to do something similar to vertical Order Traversal. Like vertical Order Traversal, we need to put nodes of same horizontal distance together. We do a level order traversal so that the topmost node at a horizontal node is visited before any other node of same horizontal distance below it. Hashing is used to check if a node at given horizontal distance is seen or not. 


// C++ program to print top
// view of binary tree
 
#include <bits/stdc++.h>
using namespace std;
 
// Structure of binary tree
struct Node {
    Node* left;
    Node* right;
    int hd;
    int data;
};
 
// function to create a new node
Node* newNode(int key)
{
    Node* node = new Node();
    node->left = node->right = NULL;
    node->data = key;
    return node;
}
 
// function should print the topView of
// the binary tree
void topview(Node* root)
{
    if (root == NULL)
        return;
    queue<Node*> q;
    map<int, int> m;
    int hd = 0;
    root->hd = hd;
 
    // push node and horizontal distance to queue
    q.push(root);
 
    cout << "The top view of the tree is : \n";
 
    while (q.size()) {
        hd = root->hd;
 
        // count function returns 1 if the container
        // contains an element whose key is equivalent
        // to hd, or returns zero otherwise.
        if (m.count(hd) == 0)
            m[hd] = root->data;
        if (root->left) {
            root->left->hd = hd - 1;
            q.push(root->left);
        }
        if (root->right) {
            root->right->hd = hd + 1;
            q.push(root->right);
        }
        q.pop();
        root = q.front();
    }
 
    for (auto i = m.begin(); i != m.end(); i++) {
        cout << i->second << " ";
    }
}
 
// Driver Program to test above functions
int main()
{
    /* Create following Binary Tree
            1
        / \
        2 3
        \
            4
            \
            5
            \
                6*/
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->right = newNode(4);
    root->left->right->right = newNode(5);
    root->left->right->right->right = newNode(6);
    cout << "Following are nodes in top view of Binary "
            "Tree\n";
    topview(root);
    return 0;
}
/* This code is contributed by Niteesh Kumar */
Output
Following are nodes in top view of Binary Tree
The top view of the tree is : 
2 1 3 6 
