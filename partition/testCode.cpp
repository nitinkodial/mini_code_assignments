// Partition: Write code to partition a linked list around a value x, such that all nodes less than x come
// before all nodes greater than or equal to x . lf x is contained within the list, the values of x only need
// to be after the elements less than x (see below) . The partition element x can appear anywhere in the
// "right partition"; it does not need to appear between the left and right partitions.
#include <iostream>
#include "../linkedList/linkedList.h"

using namespace std;

void partition(linkedList* sll,int x){
    node *ptr0 = sll->get_head();
    node *ptr2 = sll->get_head  ();
    if(ptr0==NULL){
        return;
    }
    else{
        node *ptr1 = ptr0->next;
        while(ptr1!=NULL){
            node* curr = ptr1->next;
            if(ptr1->data<x){
                ptr1->next = ptr0;
                ptr0 = ptr1;
            }
            else{
                ptr2->next = ptr1;
                ptr2 = ptr1;
            }
            ptr1 = curr;
        }
    ptr2->next = NULL;
    sll->set_head(ptr0);
    sll->set_tail(ptr2);
    
        
    }
    
}
// 6,3,2
// 3,6,2
int main() {

    linkedList sll;
    int data[] = {3,5,8,5,10,2,1};//{3,2,6,1};
    int n = sizeof(data)/sizeof(data[0]);
    sll.insert_array(data,n);

//     cout<<endl;
    sll.printNodes();
    cout<<endl;
    
    
    partition(&sll,5);

//     sll.printNodes();
    cout<<endl;
    sll.printNodes();

    return 0;
}