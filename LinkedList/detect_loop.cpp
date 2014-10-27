#include <iostream>
#include <stdlib.h>

using namespace std;

/*
Detect loop in a list
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

void create_loop(Node* head, int num){
    Node* end = head;
    Node* ptr = NULL;
    while(end->next != NULL){
        if(end->data == num)
            ptr = end;
        end = end->next;
    }
    end->next = ptr; // loop
    
}

int detect_loop(Node* head) {
    Node* fast = head; // jump by two nodes
    Node* slow = head; // jump by single node
    int iteration = 0;
    
    while(fast->next != NULL){
        iteration++;
        if(fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        } else {
            break;
        }
        
        if(fast->data == slow->data) {
            cout << "Loop is at: " << fast->data << endl;
            cout << "Number of iterations: " << iteration <<endl;
            return 1;
        }
    
    }
    cout << "There is no loop" << endl;
    cout << "Number of iterations: " << iteration <<endl;
    return 0;
}

int main(){
    Node* head = NULL;
    
    int arr[] = {15,10,5,20,3,2};
    
    int size = sizeof(arr) / sizeof(arr[0]);
    
    //create lists
    for(int i=0; i < size; i++) {
        push(&head, arr[i]);
    }
    
    //create loop at the end
    create_loop(head, 10);
    
    detect_loop(head);
    
    //print(head);
    return 0;
}


