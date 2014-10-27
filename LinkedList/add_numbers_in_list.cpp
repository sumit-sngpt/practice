#include <iostream>
#include <stdlib.h>

using namespace std;

/*
Add two numbers represented by linked lists
*/

typedef struct node {
    int data;
    struct node* next = NULL;
} Node;

void push(Node** head, int num) {
    //Node* temp = (Node*) malloc(sizeof(Node));
    Node* temp = new Node;
    temp->data = num;
    temp->next = (*head);
    (*head) = temp;
}

void print(Node* head) {
    Node* ptr = head;
    while(ptr != NULL) {
        cout << ptr->data << ",";
        ptr = ptr->next;
    }
    cout << endl;
}

int build_num(Node* head) {
    static int pos;
    int sum = 0;
    if(head == NULL) {
        pos = 1;
        return 0;
    }
        
    sum = build_num(head->next);
    cout << head->data << ",";
    int num = head->data * pos;
    pos = pos * 10;
    sum += num;
    cout << "sum is " << sum << endl; 
    return sum;
}

int main(){
    Node* first = NULL;
    Node* second = NULL;
    
    int arr1[] = {9,9,9};
    int arr2[] = {1,8};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    
    //create lists
    for(int i=0; i < size1; i++) {
        push(&first, arr1[i]);
    }
    
    for(int i=0; i < size2; i++) {
        push(&second, arr2[i]);
    }
    
    int sum = build_num(first) + build_num(second);
    cout << "Sum of two lists is " << sum << endl;
    return 0;
}


