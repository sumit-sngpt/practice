#include <iostream>

using namespace std;

/*
Binary tree traversals
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

void inorder(Node* root) {
    if(root == NULL)
        return;
    inorder(root->left);
    cout << root->data << ":";
    inorder(root->right);
}

void preorder(Node* root) {
    if(root == NULL)
        return;
    cout << root->data << ":";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root) {
    if(root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << ":";
}

int main()
{
    Node* root = newNode(1);
    root->left  = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    cout << "Preorder: " << endl;
    preorder(root);
    cout << endl;
    cout << "Inorder: " << endl;
    inorder(root);
    cout << endl;
    cout << "Postorder: " << endl;
    postorder(root);
    cout << endl;
    return 0;
}

