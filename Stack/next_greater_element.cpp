#include <iostream>
#include <stdlib.h>
#include <limits.h>


using namespace std;

/*
Print Next Greater Element for each element in an array
*/

typedef struct stack {
    unsigned int capacity;
    int top;
    char* arr;
} Stack;


Stack*  CreateStack(int cap) {
    Stack* st = (Stack*) malloc(sizeof(Stack));
    st->capacity = cap;
    st->top = 0;
    char* data = (char*) malloc(st->capacity * sizeof(char));
    st->arr = data;
    return st;
}

int isFull(Stack* st) {
    return (st->top >= st->capacity) ? 1 : 0;
}

int isEmpty(Stack* st) {
    return (st->top <= 0) ? 1 : 0;
}

void push(Stack* st, char ch) {
    if(isFull(st)) {
        cout << "No space left" << endl;
        return;        
    }
    st->arr[++st->top] = ch;
}

char pop(Stack* st) {
    if(isEmpty(st)) {
        cout << "No element to pop" << endl;
        return INT_MIN;
    }
    return st->arr[st->top--];
}

void printStack(Stack* st) {
    for(int i=st->top; i >= 0; i--) {
        cout << st->arr[i] << endl;
    }
}

int top(Stack* st) {
    return st->arr[st->top];
}

//Use Stack to evaluate Next greater element
void print_next_greater(int arr[], int size) {
    Stack* st = CreateStack(size);
    int iterations = 0;
    for(int i=0; i<size; i++){
        iterations++;
        int curr = arr[i];
        if(i==0) {
            push(st,curr);
            continue;
        }
        int prev = top(st);
        if(curr<=prev) {
            push(st,curr);
        }else{
            do {
                int num = pop(st);
                cout << num << ":" << curr << endl;
                iterations++;
            } while(!isEmpty(st) && (curr>top(st)));
            push(st,curr);
        }
    }
    //No greater elements for following
    while(!isEmpty(st)) {
        int num = pop(st);
        cout << num << ";" << -1 << endl;
    }
    cout << "Total iterations " << iterations << endl;
}

int main(){
    //int arr[] = {13,7,6,12};
    //int arr[] = {4, 5, 2, 25};
    //int arr[] = {12,11,10,9};
    int arr[] = {9,10,11,12};
    print_next_greater(arr, sizeof(arr)/sizeof(arr[0]));
    return 0;
}
