#include <iostream>
#include <queue>

using namespace std;

/*
Level order traversal - Breadth first traversal
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

void lvltraversal(Node* root) {
    queue<Node*> qu;
    if(root==NULL) {
        return;
    } else {
        qu.push(root);
    }
    while(!qu.empty()) {
        Node* ptr = qu.front();
        qu.pop();
        cout << ptr->data << endl;
        if (ptr->left)
            qu.push(ptr->left);
        if(ptr->right)
            qu.push(ptr->right);
    }
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

    lvltraversal(root);
    cout << endl;
    return 0;
}

