#include <iostream>
#include <stdlib.h>

using namespace std;

/*
Merge Sort using linked list
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

void split(Node * head, Node** a, Node** b) {
    Node* fast = head;
    Node* slow = head;
    
    while(fast->next != NULL) {
        if(fast->next->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        } else {
            break;
        }
    }
    
    Node* mid = slow;
    (*b) = mid->next;
    mid->next = NULL;
    (*a) = head;
}

void MergeSort(Node** head) {
    Node* a;
    Node* b;
    Node* head_ptr = (*head);
    if( head_ptr == NULL || head_ptr->next == NULL)
        return;
        ///////////////////
    split(*head, &a, &b); //split list into half
    print(a);
    print(b);
    MergeSort(&a); // sort each half
    MergeSort(&b);
    
//    (*head) = mergeit(&a,&b); //merge the sorted lists
}

int main(){
    Node* head = NULL;
    
    int arr[] = {15,10,5,20,3,2};
    
    int size = sizeof(arr) / sizeof(arr[0]);
    
    //create lists
    for(int i=0; i < size; i++) {
        push(&head, arr[i]);
    }
    
    MergeSort(&head);
   // print(head);
    return 0;
}


