//my linkedList implementation
#include <iostream>
#include "linkedList.h"
template <class T>

using namespace std;

// struct node {
//     int data;
//     node* next;
// };
// void class linkedList {
// private:
//     node *top,*tail;

// public:
    linkedList::linkedList() {
        top=NULL;
    }
    
    T linkedList::pop() {
        if(top==NULL){
            return NULL;
        }
        else{
            T data = top->data;
            top = top->next;
            return data;
        }
    }
    T linkedList::peek() {
       if(top==NULL){
            return NULL;
        }
        else{
            T data = top->data;
            return data;
        }
    }
    T linkedList::push(T data) {
        node* curr = new node;
        curr->data = data;
        curr->next = top;
        top = curr;
    }
    bool linkedList::isEmpty() {
        if(top==NULL){
            return true;
        }
        else{
            return false;
        }
    }
    


