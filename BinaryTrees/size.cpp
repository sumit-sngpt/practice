#include <iostream>

using namespace std;

/*
Calculate size of tree
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

int calc_size(Node* root) {
    int size = 0;
    if(root == NULL)
        return 0;
    size = calc_size(root->left) + calc_size(root->right) + 1;
    return size;
}



int main()
{
    Node* root = newNode(1);
    root->left  = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(6);

    cout << "Size of tree is " << calc_size(root);
    cout << endl;
    return 0;
}

