// Palindrome: Implement a function to check if a linked list is a palindrome.
#include <iostream>
#include "../linkedList/linkedList.h"

using namespace std;

class linkedlistptrs{
public:
    node* ptr_end;
    node* ptr_front;
};
void palindrome_helper(linkedlistptrs* obj, bool& flag);

//head is unit's place
bool palindrome(linkedList* sll1) {
    
    linkedlistptrs obj;
    obj.ptr_front = sll1->get_head();
    obj.ptr_end = sll1->get_head();
    bool flag = true;
    palindrome_helper(&obj,flag);
    return flag;
}

void palindrome_helper(linkedlistptrs* obj, bool& flag) {
//     cout<<"a"<<obj->ptr_end->data<<" "<<obj->ptr_front->data<<endl;
    if(obj->ptr_end->next==NULL) {
//          cout<<obj->ptr_end->data<<"x"<<obj->ptr_front->data<<endl;
        if(obj->ptr_end->data!=obj->ptr_front->data) {
//             cout<<obj->ptr_end->data<<"x "<<obj->ptr_front->data;
            flag = false;
        }
//         obj->ptr_front = obj->ptr_front->next;
    }
    else {
        node* prev_ptr = obj->ptr_end;
        obj->ptr_end = obj->ptr_end->next; 
        palindrome_helper(obj, flag);
        obj->ptr_end = prev_ptr;
        
        obj->ptr_front = obj->ptr_front->next;
//         cout<<obj->ptr_end->data<<" "<<obj->ptr_front->data<<endl;
        if(obj->ptr_end->data!=obj->ptr_front->data) {
//             cout<<obj->ptr_end->data<<" "<<obj->ptr_front->data<<endl;
            flag = false;
        }
    }
//     cout<<"b"<<obj->ptr_end->data<<" "<<obj->ptr_front->data<<endl;
}

// 6,3,2
// 3,6,2
int main() {

    linkedList sll1,sll2,sll3;
    int data1[] = {1,3,11,3,1};//{6,1,7};//{7,1,6};//

    int n1 = sizeof(data1)/sizeof(data1[0]);
    sll1.insert_array(data1,n1);


    //tail is unit's place
    cout<<endl<<palindrome(&sll1)<<endl;



    return 0;
}