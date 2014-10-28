#include <iostream>
#include <queue>

using namespace std;

/*
Print all ancestors of a given key
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

bool printAncestors(Node* root, int num) {
    if(root == NULL)
        return false;
    if(root->data == num)
        return true;
    
    if(printAncestors(root->left, num) || printAncestors(root->right, num)) {
        cout << root->data << ":";
        return true;
    }
    return false;
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

    printAncestors(root, 7);
    return 0;
}

