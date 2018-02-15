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
    node *top;

public:
    linkedList();
    T pop();
    T peek();
    void push(T data);
    bool isEmpty();
};
