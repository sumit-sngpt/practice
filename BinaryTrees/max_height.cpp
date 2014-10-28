#include <iostream>
#include <queue>

using namespace std;

/*
Find the Maximum Depth or Height of a Tree
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

inline int max(int num1, int num2) {
    return (num1 > num2) ? num1 : num2;
}
// return MAX height of the tree
int height(Node* root){
    if(root == NULL)
        return 0;
    return max(height(root->left), height(root->right)) + 1;
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

    cout << "MAX Height of tree is: " << height(root) << endl;
    return 0;
}

