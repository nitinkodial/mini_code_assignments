//my linkedList implementation
#include <iostream>

using namespace std;
template <class T>

struct node {
    T data;
    node* next;
};
class linkedList {
private:
    node *first;
    node *last;
    
public:
    linkedList();
    T remove();
    T peek();
    void add(T data);
    bool isEmpty();
};
