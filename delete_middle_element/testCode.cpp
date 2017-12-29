//Delete Middle Node: Implement an algorithm to delete a node in the middle (i.e., any node but
// the first and last node, not necessarily the exact middle) of a singly linked list, given only access to
// that node.
#include <iostream>
#include "../linkedList/linkedList.h"

using namespace std;

void delete_middle_element(linkedList* sll,node* ptr){
    ptr->data = ptr->next->data;
    node *tmp = ptr->next;
    ptr->next = ptr->next->next;
    delete tmp;
}

int main() {

    linkedList sll;
    int data[] = {0,1,2,3,4,5,6,7,8,9};
    int n = sizeof(data)/sizeof(data[0]);
    sll.insert_array(data,n);

//     cout<<endl;
    sll.printNodes();
    cout<<endl;
    
    node* ptr = sll.get_head();
    for(int i = 0 ;i<5;i++){
        ptr = ptr->next;
    }
    cout<<ptr->data<<endl;
    
    delete_middle_element(&sll,ptr);

//     sll.printNodes();
    cout<<endl;
    sll.printNodes();

    return 0;
}