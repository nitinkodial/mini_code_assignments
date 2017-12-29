//Loop Detection: Given a circular linked list, implement an algorithm that returns the node at the
// beginning of the loop.
#include <iostream>
#include "../linkedList/linkedList.h"

using namespace std;



node* loop_detection(linkedList* sll) {
    node* ptr0,*ptr1;
    ptr0 = sll->get_head();
    ptr1 = sll->get_head();
    
    while(ptr0!=NULL&&ptr1!=NULL){
        ptr0 = ptr0->next;
        ptr1 = ptr1->next;
        ptr1 = ptr1->next;
        if(ptr0==ptr1){
            break;
        }
    }
    if(ptr0==NULL||ptr1==NULL){
        return NULL;
    }
    else{
//         cout<<ptr0->data<<endl;
        node* ptr2 = sll->get_head();
        while(ptr1!=ptr2){
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        return ptr1;
    }
}

// 6,3,2
// 3,6,2
int main() {

    linkedList sll;
    int data1[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14};//{6,1,7};//{7,1,6};//

    int n1 = sizeof(data1)/sizeof(data1[0]);
    sll.insert_array(data1,n1);
    node* ptr = sll.get_head();
    int pointBackIndex = 12;
    for(int i=0 ;i<pointBackIndex;i++){
        ptr = ptr->next;
    }
    cout<<ptr->data<<endl;
    sll.get_tail()->next = ptr;
    
    node* loop_start = loop_detection(&sll);
    if(loop_start!=NULL){
        cout<<"start of loop is at "<<loop_start->data<<endl;
    }
    else{
        cout<<"no loops exist"<<endl;
    }
//     sll.printNodes();


    return 0;
}