// Intersection: Given two (singly) linked lists, determine if the two lists intersect. Return the inter-
// secting node. Note that the intersection is defined based on reference, not value. That is, if the kth
// node of the first linked list is the exact same node (by reference) as the jth node of the second
// linked list, then they are intersecting.
#include <iostream>
#include "../linkedList/linkedList.h"

using namespace std;



node* intersection(linkedList* sll1,linkedList* sll2) {
//     node* intersection_node = NULL;
    node *ptr1 = sll1->get_head();
    node *ptr2 = sll2->get_head();
    
    while(ptr1->next!=NULL){
      ptr1=ptr1->next;   
    }
    while(ptr2->next!=NULL){
      ptr2=ptr2->next;   
    }
    if(ptr1!=ptr2){
        return NULL;
    }
    else{
        int n1 = sll1->get_length();
        int n2 = sll2->get_length();
        ptr1 = sll1->get_head();
        ptr2 = sll2->get_head();
    
        if(n1>n2){
          for(int i = 0;i<(n1-n2);i++){
              ptr1 = ptr1->next;
          }
          while(ptr1!=ptr2){
              ptr1 = ptr1->next;
              ptr2 = ptr2->next;
          }
        }
        else if(n1<n2){
          for(int i = 0;i<(n2-n1);i++){
              ptr2 = ptr2->next;
          }
          while(ptr1!=ptr2){
              ptr1 = ptr1->next;
              ptr2 = ptr2->next;
          }  
        }
        return ptr1;
    }
    
}

// 6,3,2
// 3,6,2
int main() {

    linkedList sll1,sll2;
    int data1[] = {0,1,2,3,4,5};//{6,1,7};//{7,1,6};//

    int n1 = sizeof(data1)/sizeof(data1[0]);
    sll1.insert_array(data1,n1);
    
    int data2[] = {6,7,8,9,10,11};//{6,1,7};//{7,1,6};//

    int n2 = sizeof(data2)/sizeof(data2[0]);
    sll2.insert_array(data2,n2);
    
    sll1.get_tail()->next = sll2.get_head();
//     sll2.printNodes();
    node* common_node = intersection(&sll1,&sll2);
    if(common_node!=NULL){
        cout<<common_node->data<<endl;
    }
    else{
        cout<<"no intersecting node"<<endl;
    }

    return 0;
}