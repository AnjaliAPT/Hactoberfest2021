#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    struct Node* left;
    struct Node* right;
    
    Node(int val)
    {
        key=val;
        left=right=NULL;
    }
};

int getSize(struct Node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    return 1+getSize(root->left)+getSize(root->right);
}

int main()
{
    struct Node* root=new Node(10);
    root->left=new Node(20);
    root->right=new Node(30);
    root->right->left=new Node(40);
    root->right->right=new Node(50);        
   cout<<getSize(root)<<endl;
    
}
