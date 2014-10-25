#include <iostream>
#include <stdlib.h>

using namespace std;

/*
Print reverse of a linked list recursively
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

void print_reverse(Node* ptr) {
    // print recursively
    if ( ptr == NULL)
        return;
        
    print_reverse(ptr->next);
    cout << ptr->data << ",";
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
    print_reverse(head);
    return 0;
}


