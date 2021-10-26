#include<iostream>

using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node * root = NULL;

struct Node* newNode(int data){
    struct Node * node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

void preorder_recursive_traversal(struct Node* node){
    if(node == NULL){
        return;
    }
    cout<<node->data<<" ";
    preorder_recursive_traversal(node->left);
    preorder_recursive_traversal(node->right);
}

int main(){
    root = newNode(5);
    root -> left = newNode(10);
    root -> right = newNode(15);
    root -> left -> left = newNode(12); 
    root -> left -> right = newNode(13); 
    root -> right -> left = newNode(14); 
    root -> right -> right = newNode(17);

    preorder_recursive_traversal(root);

    //      5
    //     / \ 
    //   10   15
    //  / \   / \ 
    // 12 13 14 17
}