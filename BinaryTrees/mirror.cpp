#include <iostream>
#include <queue>

using namespace std;

/*
Create mirror of a binary tree
*/

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} Node;

Node* newNode(int num) {
    Node* ptr = new Node;
    ptr->data = num;
    ptr->right = NULL;
    ptr->left = NULL;
    return ptr;
}

void swap(Node* root, Node* left, Node* right) {
    root->left = right;
    root->right = left;
}

Node* mirror(Node* root) {
    if ( root == NULL )
        return root;
    
    Node* left = mirror(root->left);
    Node* right = mirror(root->right);
    
    swap(root, left, right);
    
    return root;
}

void print(Node* root) {
    if(root==NULL)
        return;
    print(root->left);
    cout << root->data << ":";
    print(root->right);
}

int main()
{
    Node* root = newNode(1);
    root->left  = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(6);
    root->right->right->left = newNode(7);

    print(root);
    cout << endl;
    Node* mirr = mirror(root);
    print(root);
    cout << endl;
    return 0;
}

