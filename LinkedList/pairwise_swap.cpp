#include <iostream>
#include <stdlib.h>

using namespace std;

/*
Pairwise swap elements of a given linked list
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

void swap(Node* head) {
    Node* ptr = head;
    if(ptr == NULL || ptr->next == NULL)
        return;
    //swap here
    int data = ptr->data;
    ptr->data = ptr->next->data;
    ptr->next->data = data;
    swap(ptr->next->next);
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
    //push(&head, 71);
    
    print(head);
    swap(head);
    print(head);
    return 0;
}


