#include <iostream>
#include <stdlib.h>

using namespace std;

/*
Print the middle of a given linked list
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

int fetch_middle(Node* head) {
    Node* first_ptr = head;
    Node* second_ptr = head;
    // first ptr traverse list one by one
    // second ptr traverse list jump by two
    while(second_ptr->next != NULL) {
        //cout << first_ptr->data << "," << second_ptr->data << endl;
        if(second_ptr->next->next !=NULL) {
            second_ptr = second_ptr->next->next;
            first_ptr = first_ptr->next;
        } else {
            break;
        }
    }
    return first_ptr->data;
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
    
    int mid = fetch_middle(head);
    cout << "Middle element is " << mid << endl;
    return 0;
}


