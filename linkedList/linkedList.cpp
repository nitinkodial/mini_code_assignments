//my linkedList implementation
#include <iostream>
#include "linkedList.h"

using namespace std;

// struct node {
//     int data;
//     node* next;
// };
// void class linkedList {
// private:
//     node *head,*tail;

// public:
    linkedList::linkedList() {
        head=NULL;
        tail=NULL;
    }
    
    node* linkedList::get_tail(){
        return tail;
    }
    node* linkedList::get_head(){
        return head;
    }
    void linkedList::set_tail(node* ptr){
        tail = ptr;
    }
    void linkedList::set_head(node* ptr){
        head = ptr;
    }
    
    int linkedList::get_length(){
        int i = 0;
        node* ptr = head;
        while(ptr!=NULL){
            ptr=ptr->next;
            i++;
        }
        return i;
    }
    
    void linkedList::update_tail(){
        if(head==NULL){
            tail = head;
        }
        else{
            node* tmp = head;
            while(tmp->next!=NULL){
                tmp = tmp->next;
            }
            tail = tmp;
        }
    }
    
    void linkedList::insert_array(int* data, int n) {
        for(int i = 0;i<n;i++){
            insert_end(data[i]);
        }
    }
    
    void linkedList::insert_end(int data) {
        node *tmp = new node;
        tmp->data = data;
        tmp->next = NULL;
        if(head==NULL) {
            head = tmp;
            tail = tmp;
        }
        else {
            tail->next = tmp;
            tail = tail->next;
        }

    }
    void linkedList::insert_front(int data) {
        node *tmp = new node;
        tmp->data = data;
        tmp->next = NULL;
        if(head==NULL) {
            head = tmp;
            tail = tmp;
        }
        else {
            tmp->next = head;
            head = tmp;
        }
    }
    void linkedList::insert_pos(int data,int n) {
        node *tmp = new node;
        tmp->data = data;
        tmp->next = NULL;
        //if insert at front
        if(n==0) {
            insert_front(data);
        }
        else {
            int  i = 0;
            node *prev=head;
            node *curr=prev->next;
            while(curr!=NULL) {
//                 cout<<i<<" "<<prev->data<<" "<<curr->data<<endl;
                if(i==n-1) {
                    prev->next = tmp;
                    tmp->next = curr;
                    break;
                }
                prev = prev->next;
                curr=curr->next;
                i++;
            }
            //if insert at end
            if(i==n-1) {
                    prev->next = tmp;
                    tmp->next = curr;
//                     break;
            }
        }
    }
    
    void linkedList::delete_end() {
        node *tmp = head;
        if(head==NULL) {
            return;
        }
        else {
            while(tmp->next->next!=NULL){
                tmp = tmp->next;
            }
            delete tmp->next;
            tmp->next = NULL;
            tail = tmp;
        }

    }
    void linkedList::delete_front() {
        
        node *tmp = head;
        if(head==NULL) {
            return;
        }
        head = head->next;
        delete tmp;
    }
    
    void linkedList::delete_pos(int n) {
        //if delete at front
        if(n==0) {
            delete_front();
        }
        else {
            int  i = 0;
            node *prev=head;
            node *curr=prev->next;
            while(curr!=NULL) {
//                 cout<<i<<" "<<prev->data<<" "<<curr->data<<endl;
                if(i==n-1) {
                    prev->next = curr->next;
                    delete curr;
                    break;
                }
                prev = prev->next;
                curr=curr->next;
                i++;
            }
        
        }
    }
    
    void linkedList::printNodes() {
        if(head==NULL) {
            return;
        }
        else {
            node *tmp=head;
            while(tmp!=NULL) {
                cout<<tmp->data<<endl;
                tmp=tmp->next;
            }
        }

    }
// };


