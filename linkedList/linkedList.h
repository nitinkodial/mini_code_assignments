//my linkedList implementation
#include <iostream>

using namespace std;

struct node {
    int data;
    node* next;
};
class linkedList {
private:
    node *head,*tail;

public:
    linkedList();
    node* get_head();
    node* get_tail();
    
    void set_head(node* ptr);
    void set_tail(node* ptr);
    
    void update_tail();
    void insert_end(int data);
    void insert_front(int data);
    void insert_pos(int data,int n);
    
    void delete_end();
    void delete_front();
    
    void delete_pos(int n);
    void insert_array(int* data,int n);
    void printNodes();
    int get_length();
};
