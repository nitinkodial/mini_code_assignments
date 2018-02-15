// You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

// You may assume the two numbers do not contain any leading zero, except the number 0 itself.
// Example
// 
// Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
// Output: 7 -> 0 -> 8
// Explanation: 342 + 465 = 807.

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
        int a = 0,b=0,carry = 0,sum = 0 ;
        ListNode*  sumList = new ListNode(0) ;
        ListNode* ptr = sumList;
        ListNode* head =ptr;
        while(l1!=NULL&&l2!=NULL){
            a = l1->val;
            b = l2->val;
            sum = a + b + carry;
            ptr->val = sum%10;
            carry = sum/10;
            l1=l1->next;
            l2=l2->next;
            if(l1!=NULL&&l2!=NULL){
                ptr->next = new ListNode(0);
                ptr = ptr->next;
            }
            else{
                ptr->next = NULL;
            }
            
        }
        while(l1!=NULL){
            ptr->next = new ListNode(0);
            ptr = ptr->next;
            
            a = l1->val;
            b = 0;
            sum = a + b + carry;
            ptr->val = sum%10;
            carry = sum/10;
            l1=l1->next;
            if(l1!=NULL){
                //ptr->next = new ListNode(0);
                //ptr = ptr->next;
            }
            else{
                ptr->next = NULL;
            }    
        }
        while(l2!=NULL){
            ptr->next = new ListNode(0);
            ptr = ptr->next;
            
            b = l2->val;
            a = 0;
            sum = a + b + carry;
            ptr->val = sum%10;
            carry = sum/10;
            l2=l2->next;
            if(l2!=NULL){
                //ptr->next = new ListNode(0);
                //ptr = ptr->next;
            }
            else{
                ptr->next = NULL;
            }    
        }
        if(carry>0){
            ptr->next = new ListNode(carry);
            ptr = ptr->next;
        }
        ptr = NULL;
        ptr=head;
        while(ptr!=NULL){
            cout<<ptr->val<<endl;
            ptr=ptr->next;
        }
        return head;
    }
};