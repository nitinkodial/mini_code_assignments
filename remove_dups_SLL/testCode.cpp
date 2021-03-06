// Remove Dups: Write code to remove duplicates from an unsorted li nked list.
#include <iostream>
#include "../linkedList/linkedList.h"
#include <map>

using namespace std;

void remove_dups1(linkedList* sll) {
    node *ptr0 = sll->get_head();
    if(ptr0==NULL||ptr0->next==NULL) {
        return;
    }

    node *ptr1 = ptr0;

    while(ptr0!=NULL) {
        ptr1 = ptr0;
        while(ptr1->next!=NULL) {
            if(ptr0->data == ptr1->next->data) {
//                 cout<<ptr1->next->data<<endl;
                node *tmp = ptr1->next;
                ptr1->next = ptr1->next->next;
                delete tmp;
            }
            else {
                ptr1 = ptr1->next;
            }
        }
//         cout<<endl;
        ptr0 = ptr0->next;
    }
    sll->update_tail();

}
void remove_dups2(linkedList* sll) {

    node *ptr0 = sll->get_head();
    if(ptr0==NULL||ptr0->next==NULL) {
        return;
    }

    node *ptr1 = ptr0->next;

    map<int,int> fMap;
    //add data of head
    fMap.insert(make_pair(ptr0->data,1));

    int i = 0;
    while(ptr1!=NULL) {
//         cout<<ptr1->data<<endl;
        map<int,int>::iterator it = fMap.find(ptr1->data);
        if(it!=fMap.end()) {
            ptr0->next = ptr1->next;
            delete ptr1;
            ptr1 = ptr0->next;
        }
        else {
            fMap.insert(make_pair(ptr1->data,1));
            ptr0 = ptr0->next;
            ptr1=ptr1->next;

        }
    }
    sll->update_tail();

}

int main() {

    linkedList sll;
    int data[] = {0,1,2,4,1,3,0,4};
    int n = sizeof(data)/sizeof(data[0]);
    sll.insert_array(data,n);

    sll.printNodes();
    cout<<endl;
    remove_dups1(&sll);
    sll.printNodes();

    return 0;
}