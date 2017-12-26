//check if 1 array is subset (non contiguous) of another array
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

    void insert_end(int data);
    void insert_front(int data);
    void insert_pos(int data,int n);
    
    void delete_end();
    void delete_front();
    
    void delete_pos(int n);
    
    void printNodes();
};
