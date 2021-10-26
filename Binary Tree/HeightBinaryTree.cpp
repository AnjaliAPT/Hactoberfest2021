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

int height(struct Node* node){
    if(node == NULL){
        return 0;
    } 
    return max(height(node->left), height(node->right))+1;
}

int main(){
    root = newNode(5);
    root -> left = newNode(10);
    root -> right = newNode(15);
    root -> left -> left = newNode(12); 
    root -> left -> right = newNode(13); 
    root -> right -> left = newNode(14); 
    root -> right -> right = newNode(17);

    cout<<"Height of the tree : "<<height(root);

    //      5        
    //     / \ 
    //   10   15
    //  / \   / \ 
    // 12 13 14 17
}