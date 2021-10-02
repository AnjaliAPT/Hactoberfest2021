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

int getMax(struct Node* root)   // max elemet in the node
{
    if(root==NULL)
    {
        return INT_MIN;
    }
    return max(root->key,max(getMax(root->left),getMax(root->right)));
}

int getMin(struct Node* root)  //min element in the node
{
    if(root==NULL)    
    {
        return INT_MAX;
    }
    return min(root->key,min(getMin(root->left),getMin(root->right)));
}

int main()
{
    struct Node* root=new Node(10);
    root->left=new Node(20);
    root->right=new Node(30);
    root->right->left=new Node(40);
    root->right->right=new Node(50);        
    
   cout<<getMax(root)<<endl;
   cout<<getMin(root)<<endl;
    
}
