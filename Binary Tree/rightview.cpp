#include<iostream>
#include<queue>
using namespace std;
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
vector<int> rightView(Node *root)
    {
       // Your Code here
       vector<int>ans;
       queue<Node*>q;
       q.push(root);
       while(!q.empty()){
           int n = q.size();
           for(int i = 0;i<n;i++){
               Node*a = q.front();
               q.pop();
               if(i==n-1) ans.push_back(a->data);
               if(a->left) q.push(a->left);
               if(a->right) q.push(a->right);
           }
       }
       return ans;
    }
int main(){
    Node *root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->right->right=new Node(5);
    vector<int>ans=rightView(root)
    for (int i:ans) cout<<i<<" ";
    return 0;
}
