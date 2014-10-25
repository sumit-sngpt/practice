#include <iostream>
#include <stdlib.h>

using namespace std;

/*
Reverse a list using only three pointers
*/

typedef struct node {
    int data;
    struct node* next = NULL;
} Node;

void push(Node** head, int num) {
    Node* temp = (Node*) malloc(sizeof(Node));
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

// Reverse a linked list using three pointers
Node* reverse(Node** head) {
    Node* new_head = NULL;
    while((*head) != NULL){
        Node* temp = (*head);
        (*head) = (*head)->next;
        temp->next = new_head;
        new_head = temp;
    }
    (*head) = new_head;
    return new_head; // required only if you want to return a new linked list
}

int main(){
    Node* head = NULL;
    
    push(&head, 5);
    push(&head, 51);
    push(&head, 25);
    push(&head, 15);
    push(&head, 31);
    push(&head, 46);
    push(&head, 65);
    push(&head, 71);
    
    print(head);
    Node* new_head = reverse(&head);
    print(new_head); // or, print(head)
    return 0;
}


