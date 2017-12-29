//Return Kth to Last: Implement an algorithm to find the kth to last element of a singly linked list.
#include <iostream>
#include "../linkedList/linkedList.h"
#include <map>

using namespace std;

//actually deletes kth element from last
void kth_last_element(linkedList* sll,int k1) {
    
    int k = k1;
    if(sll->get_head()==NULL||k<0){
        return;
    }
    else if((sll->get_head()==sll->get_tail())&&k==0){
        sll->delete_front();
        return;
    }
     
    else if((sll->get_head()==sll->get_tail())&&k>0){
        return;
    }
    
    k = k1;
    
    node *lead_ptr,*lag_ptr;
    int i = 0;
    lag_ptr = sll->get_head();
    lead_ptr = lag_ptr;
    for(int i = 0;i<k;i++){
//         cout<<lead_ptr->data<<endl;
        if(lead_ptr->next!=NULL){
            lead_ptr = lead_ptr->next;
        }
        else{
            return;
        }
    }
//     if(lead_ptr==
//     cout<<"d1"<<endl;   
    if(lead_ptr->next==NULL){
        sll->delete_front();
        return;
    }
    lead_ptr = lead_ptr->next;
//     cout<<"d1"<<endl;   
    while(lead_ptr->next!=NULL){
//      cout<<lag_ptr->data<<" "<<lead_ptr->data<<" "<<endl;
     lead_ptr = lead_ptr->next;
     lag_ptr = lag_ptr->next;
    }
    node* tmp = lag_ptr->next;
    lag_ptr->next = lag_ptr->next->next;
    delete tmp;
//     cout<<lag_ptr->data<<" x "<<endl;       
    

}

void kth_last_element2_helper(linkedList* sll,node* ptr, int k, int& i) {
//     cout<<ptr->data<<endl;
   
    if(ptr->next==NULL){
        i = 0;
        return;
    }
    else{
        kth_last_element2_helper(sll,ptr->next,k, i);
        i++;
        if((i-1)==k){
            cout<<ptr->next->data<<endl;
//             cout<<"x"<<i<<endl;            
        }
    }

}

//just displays kth element from last
void kth_last_element2(linkedList* sll,node* ptr, int k, int& i) {
    kth_last_element2_helper(sll,ptr,k, i);
    //if k points to head pointer's data
    i++;
    if((i-1)==k){
            cout<<ptr->data<<endl;
    }
//     cout<<"x"<<i<<endl;
}


int main() {

    linkedList sll;
    int data[] = {0,1,2,3,4,5,6,7,8,9};
    int n = sizeof(data)/sizeof(data[0]);
    sll.insert_array(data,n);

//     cout<<endl;
    sll.printNodes();
    cout<<endl;
    
//     kth_last_element(&sll,-10);
    int i = 0;
    node* ptr = sll.get_head();
    kth_last_element2(&sll,ptr,0,i);

//     sll.printNodes();
    cout<<endl;
    sll.printNodes();

    return 0;
}