/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    
    int carry = 0;
    ListNode *curr = l1;
    while(curr || l2){
        int l1_val = curr ? curr->val : 0;
        int l2_val = l2 ? l2->val : 0;
        int sum = l1_val + l2_val + carry;
        curr->val  = sum %10;
        carry = sum / 10;
        if(!curr->next  && ((l2 && l2->next ) || carry != 0)){
            curr->next = new ListNode(0);
        }
        l2 = l2 ? l2->next : nullptr;
        curr = curr->next;
    }
    return l1;
    
    }
};
