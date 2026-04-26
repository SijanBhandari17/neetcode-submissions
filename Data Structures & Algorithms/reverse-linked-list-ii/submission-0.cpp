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

void reverseList(ListNode *head,ListNode *tail){
    ListNode *prev = head;
    head = head->next;
    prev->next = nullptr;

    while(head){
        ListNode *temp = head->next;
        head->next = prev;
        prev = head;
        head = temp;
    } 
}

ListNode* reverseBetween(ListNode* head, int left, int right) {
    ListNode *first = head;
    ListNode *dummy = new ListNode(0,head);
    ListNode *second = dummy;
    ListNode *rem_l = new ListNode();
    ListNode *rem_f = new ListNode();

    while(right > 1){
        first = first->next;
        right--; 
    }
    rem_l = first->next;
    first->next = nullptr;
    while(left > 1){
        second = second->next;
        left--;
    }
    rem_f = second->next;
    reverseList(second->next,first);
    second->next = first;
    rem_f->next = rem_l;
    return dummy->next;
}
};