///// Shortest distance between 2 nodes//////////
////Strategy : the path go from LCA(lowest common ancestor) so distance = d1(node1 to LCA) + d2(node2 to LCA)
# include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node*left;
    Node*right;

   Node(int val)
   {
       data = val;
       left=NULL;
       right =NULL;
   }

};
//Lowest Common Ancestor
Node* LCA(Node*root, int n1, int n2){

if(root==NULL)return NULL ;
if(root->data==n1 ||root->data==n2)return root;

Node* Llca = LCA(root->left, n1,n2);
Node* Rlca = LCA(root->right, n1,n2);

if(Llca!=NULL && Rlca!=NULL)
{
    // this condition true when n1 lies of left subtree 
    //and n2 on right subtree or viceversa
    return root;
}

if(Llca!=NULL)
{
   
    return Llca;
}
if(Rlca!=NULL)
{
   
    return Rlca;
}
return NULL;
}
int findDistance(Node*root, int k ,int dist){

    if(root==NULL){
        return -1;
    }

    if(root->data == k)
    {
        return dist;
    }

    int left = findDistance(root->left, k ,dist+1);
    if(left!= -1)
    {
        return left;
    }
     return findDistance(root->right, k , dist+1);
}
int disOfNodes(Node*root, int n1,int n2)
{
    Node* lca= LCA(root,n1,n2);

    int d1 = findDistance(lca,n1,0);
     int d2 = findDistance(lca,n2,0);
     return d1+d2;
}

int main(){

          /*            1
                      /   \
                     2     3
                    / \
                   4   5                        */
    Node * root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
     root->left->left = new Node(4);
    root->left->right = new Node(5);
   
  cout<<disOfNodes(root, 5,3);
    return 0;
}