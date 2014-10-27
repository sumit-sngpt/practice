#include <iostream>
#include <stdlib.h>

using namespace std;

/*
Print alternate nodes from head to end and then end to head
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

void print_alt(Node* head) {
    if(head == NULL)
        return;
    cout << head->data << ",";
    
    if (head->next != NULL) // alternate traversal from head to end
        print_alt(head->next->next);
    
    // now print alternate from end to head
    cout << head->data << ":";
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
   // push(&head, 71);
    
    print(head);
    print_alt(head); //print alternate nodes
    return 0;
}


