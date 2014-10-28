#include <iostream>
#include <stdlib.h>

using namespace std;

/*
Maximum width of a binary tree
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

// return MAX height of the tree
int height(Node* root){
    if(root == NULL)
        return 0;
    return max(height(root->left), height(root->right)) + 1;
}

void MaxWidthUtil(Node*, int*, int);

int getMaxWidth(Node* root) {
    int arr_size = height(root);
    //count array will have width for each level by index
    int* count = (int*) malloc(sizeof(int) * arr_size);
    
    //start traverse and fill up the array
    MaxWidthUtil(root, count, 0);
    
    //find out MAX from count array
    int max_width = 0;
    for(int i=0; i<arr_size; i++){
        max_width = (max_width < count[i]) ? count[i] : max_width;
    }
    return max_width;
}

void MaxWidthUtil(Node* root, int* count, int level) {
    
    if(root!=NULL){
        count[level]+=1;
        MaxWidthUtil(root->left, count, level+1);
        MaxWidthUtil(root->right, count, level+1);
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
    
    int maxwidth = getMaxWidth(root);
    cout << "MAX width of this binary tree is " << maxwidth << endl;
    
    return 0;
}

