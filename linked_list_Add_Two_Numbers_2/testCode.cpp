// You are given two non-empty linked lists representing two non-negative integers. The digits are stored in correct order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

// You may assume the two numbers do not contain any leading zero, except the number 0 itself.
// Example
// 
// Input: (3 -> 4 -> 2) + (4 -> 6 -> 5)
// Output: 8 -> 0 -> 7
// Explanation: 342 + 465 = 807.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head =  new ListNode(0);
        ListNode *l1Orig=l1,*l2Orig=l2;
        int sz1=0,sz2=0;
        while(l1!=NULL){
            sz1++;
            l1 = l1->next;
        }
        while(l2!=NULL){
            sz2++;
            l2 = l2->next;
        }
        l1 = l1Orig;
        l2 = l2Orig;
        if(sz1==sz2){
            int carry =0;
            ListNode* headOrig = head;
            addTwoNumbersHelper(head,l1,l2,carry);
            head = headOrig;
            head = addCarryToHead(head,carry);

        }
        else if(sz1>sz2){
            ListNode* l1n=l1;
            for(int i=0;i<(sz1-sz2);i++){
                l1n = l1n->next;
            }
            int carry =0;
            ListNode* headOrig = head;
            addTwoNumbersHelper(head,l1n,l2,carry);
            head = headOrig;
            ListNode* ptr = NULL;
            l1 = l1Orig;
            l2 = l2Orig;
            ptr = addRemainingNodes(l1,ptr,sz1-sz2,carry,head);
            head = ptr;
            while(ptr!=NULL){
                //cout<<ptr->val<<endl;
                ptr = ptr->next;
            }
            //head = ptr;
            head = addCarryToHead(head,carry);
            
        }
        else{
            ListNode* l2n=l2;
            for(int i=0;i<(sz2-sz1);i++){
                l2n = l2n->next;
            }
            int carry =0;
            ListNode* headOrig = head;
            addTwoNumbersHelper(head,l1,l2n,carry);
            head = headOrig;
            ListNode* ptr=NULL;
            l1 = l1Orig;
            l2 = l2Orig;
            ptr = addRemainingNodes(l2,ptr,sz2-sz1,carry,head);
            head = ptr;
            head = addCarryToHead(head,carry);
        }
        ////cout<<sz1<<" "<<sz2<<endl;
        return head;
    }
    ListNode* addRemainingNodes(ListNode* ll,ListNode* ptr,int diff,int& carry,ListNode* head){
        if(diff==0){
            return ptr;
        }
        else{
            //cout<<ll->val<<" xx"<<diff<<" "<<head->val<<endl;
            ptr = new ListNode(ll->val);
            if(diff-1==0){
               ptr->next = head; 
            }
            else{
                ptr->next  = NULL;
            }
            ptr->next = addRemainingNodes(ll->next,ptr->next,diff-1,carry,head);
            ptr->val = ptr->val + carry;
            carry = ptr->val/10;
            ptr->val =  (ptr->val)%10;
            ////cout<<ptr->val<< " xy"<<carry<<endl;
            ////cout<<ptr->next->val<<" xz"<<endl;
            return ptr;
        }
        
    }
    
    ListNode* addCarryToHead(ListNode* head,int carry){
        if(carry>0){
                ListNode* ptr2 = new ListNode(carry);
                ptr2->next = head;
                head = ptr2;
        }
        return head;
    } 
    
    void addTwoNumbersHelper(ListNode* ptr,ListNode* l1,ListNode* l2,int& carry){
        if(l1==NULL&&l2==NULL){
            return;
        }
        else{
            if(l1->next!=NULL&&l2->next!=NULL){
                ptr->next = new ListNode(0);
            }
            carry=0;
            addTwoNumbersHelper(ptr->next,l1->next,l2->next,carry);
            int a = l1->val;
            int b = l2->val;
            int sum = a + b + carry;
            ptr->val = sum%10;
            carry = sum/10;
            //cout<<"x"<<ptr->val <<" "<<a<<" "<<b<<" "<<carry <<endl;
        }
    }
};