// Sum Lists: You have two numbers represented by a linked list, where each node contains a single
// digit. The digits are stored in reverse order, such that the 1 's digit is at the head of the list. Write a
// function that adds the two numbers and returns the sum as a linked list.
#include <iostream>
#include "../linkedList/linkedList.h"

using namespace std;

//head is unit's place
void sum_lists(linkedList* sll1,linkedList* sll2,linkedList* sll3) {
    int carry = 0;
    node* ptr1 = sll1->get_head();
    node* ptr2 = sll2->get_head();
    while(ptr1!=NULL||ptr2!=NULL) {
//         cout<<carry<<endl;
        if(ptr1!=NULL&&ptr2!=NULL) {
//             cout<<"d"<<ptr1->data<<" "<<ptr2->data<<endl;
            int sum = ptr1->data+ptr2->data+carry;
            carry = sum/10;
            sum = sum%10;
            sll3->insert_end(sum);
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        else if(ptr1!=NULL) {
//             cout<<ptr1->data<<" "<<carry;
            sll3->insert_end(ptr1->data+carry);
            ptr1 = ptr1->next;
            carry=0;
        }
        else if(ptr2!=NULL) {
            cout<<ptr2->data<<" "<<carry;
            sll3->insert_end(ptr2->data+carry);
            ptr2 = ptr2->next;
            carry=0;
        }
    }
    if(carry!=0){
        sll3->insert_end(carry);
    }
}


void sum_lists2_helper(node* ptr1,node* ptr2,linkedList* sll3,int& carry);


//tail is unit's place
void sum_lists2(linkedList* sll1,linkedList* sll2,linkedList* sll3) {
    int n1 = sll1->get_length();
    int n2 = sll2->get_length();
    if(n1<n2){
        for(int i=0;i<(n2-n1);i++){
            sll1->insert_front(0);   
        }
    }
    if(n1>n2){
        for(int i=0;i<(n1-n2);i++){
            sll2->insert_front(0);   
        }
    }

    int carry = 0;
    node* ptr1 = sll1->get_head();
    node* ptr2 = sll2->get_head();
    sum_lists2_helper(ptr1,ptr2,sll3,carry);
    if(carry!=0){
        sll3->insert_front(carry);
    }
}

void sum_lists2_helper(node* ptr1,node* ptr2,linkedList* sll3,int& carry){
    if(ptr1->next==NULL&&ptr2->next==NULL){
        int sum = ptr1->data+ptr2->data+carry;
        carry = sum/10;
        sum = sum%10;
        sll3->insert_front(sum);
    }
    else{
        sum_lists2_helper(ptr1->next,ptr2->next,sll3,carry);
        int sum = ptr1->data+ptr2->data+carry;
        carry = sum/10;
        sum = sum%10;
        sll3->insert_front(sum);
    }
}

// 6,3,2
// 3,6,2
int main() {

    linkedList sll1,sll2,sll3;
    int data1[] = {9,7,8,9};//{6,1,7};//{7,1,6};//
    int data2[] = {6,8,5};//{2,9,5};//{5,9,2};//

    int n1 = sizeof(data1)/sizeof(data1[0]);
    int n2 = sizeof(data2)/sizeof(data2[0]);
    sll1.insert_array(data1,n1);
    sll2.insert_array(data2,n2);

    //head is unit's place
//     sum_lists(&sll1,&sll2,&sll3);
    
    //tail is unit's place
    sum_lists2(&sll1,&sll2,&sll3);


//     sll.printNodes();
    cout<<endl;
    sll3.printNodes();

    return 0;
}