#include <iostream>
#include <stdlib.h>
#include <limits.h>


using namespace std;

/*
Reverse a string using stack
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

void reverse(string str) {
    Stack* st = CreateStack(str.length());
    for(int i=0; i<str.length(); i++){
        push(st,str[i]);
    }
    
    //fetch from stack one by one and add to the new string
    int i = 0;
    char* revstr = (char*) malloc(str.length()*sizeof(char));
    while(!isEmpty(st)) {
        char ch = pop(st);
        revstr[i++] = ch;
    }
    revstr[i] = '\0';
    cout << str << endl;
    cout << revstr << endl;
}


int main(){
    
    string str = "sumitsengupta";
    reverse(str);
    return 0;
}
