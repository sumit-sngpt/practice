#include <iostream>
#include <queue>

using namespace std;

/*
Get Level of a node in a Binary Tree
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

int getlevel(Node* root, int num) {
    if(root==NULL)
        return 0;
    if(root->data == num)
        return 1;
    int level = getlevel(root->left,num) + getlevel(root->right,num);
    if(level>0)
        return level+1;
    else
        return 0;
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

    int level = getlevel(root, 1);
    cout << "Level is " << level << endl;
    level = getlevel(root, 2);
    cout << "Level is " << level << endl;
    level = getlevel(root, 5);
    cout << "Level is " << level << endl;
    level = getlevel(root, 7);
    cout << "Level is " << level << endl;
    level = getlevel(root, 100);
    cout << "Level is " << level << endl;
    
    return 0;
}

