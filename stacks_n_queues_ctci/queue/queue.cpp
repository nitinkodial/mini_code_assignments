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
//     node *first,*tail;

// public:
    linkedList::linkedList() {
        first=NULL;
        last=NULL;
    }
    
    T linkedList::remove() {
        if(first==NULL){
            return NULL;
        }
        else{
            T data = first->data;
            first = first->next;
            if(first==NULL){
                last = first;
            }
            return data;
        }
    }
    T linkedList::peek() {
       if(first==NULL){
            return NULL;
        }
        else{
            T data = first->data;
            return data;
        }
    }
    T linkedList::add(T data) {
        node* curr = new node;
        curr->data = data;
        if(last!=NULL){
         last.next = curr;   
        }
        last = curr;
        if(first==NULL){
            first = last;
        }
    }
    bool linkedList::isEmpty() {
        if(first==NULL){
            return true;
        }
        else{
            return false;
        }
    }
    


