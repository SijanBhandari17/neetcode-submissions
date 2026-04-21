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
    void reorderList(ListNode* head) {
        // mid
        ListNode* s = head;
        ListNode* f = head;
        while (f && f->next) {
            f = f->next->next;
            s = s->next;
        }
        ListNode* mid = s;

        ListNode* second = mid->next;
        mid->next = nullptr;
        ListNode* prev = nullptr;
        while (second) {
            ListNode* temp = second->next;
            second->next = prev;
            prev = second;
            second = temp;
        }

        mid = prev;  

        while (mid) {
            ListNode* next_1 = head->next;
            head->next = mid;
            ListNode* next_2 = mid->next;
            mid->next = next_1;
            head = next_1;
            mid = next_2;
        }
    }
};
