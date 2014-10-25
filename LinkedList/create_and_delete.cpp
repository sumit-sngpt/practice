#include <iostream>
#include <stdlib.h>

using namespace std;

/*
Given only a pointer to a node to be deleted in a singly linked list, how do you delete it?
*/

struct node {
    int data;
    struct node* next = NULL;
};

void push(struct node** head, int num) {
    struct node* temp = (struct node*) malloc(sizeof(struct node));
    temp->data = num;
    temp->next = (*head);
    (*head) = temp;
}

void print(struct node* head) {
    struct node* ptr = head;
    while(ptr != NULL) {
        cout << ptr->data << ",";
        ptr = ptr->next;
    }
    cout << endl;
}

void deletehead(struct node** head) {
    struct node* temp = (*head);
    (*head) = temp->next;
    free(temp);
}

int main(){
    struct node* head = NULL;
    
    push(&head, 5);
    push(&head, 51);
    push(&head, 25);
    push(&head, 15);
    
    print(head);
    
    deletehead(&head);
    print(head);
    
    return 0;
}


