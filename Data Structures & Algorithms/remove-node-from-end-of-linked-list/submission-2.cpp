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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* curr = head;
        int count = 0;
        while (curr) {
            count++;
            curr = curr->next;
        }
        int to_delete = count - n;
        int i = 0;
        if(to_delete == 0){
            return head->next;
        }
        curr = head;
        while (curr) {
            if (i + 1 == to_delete) {
                curr->next = curr->next->next;
                return head;
            }
            curr = curr->next;
            i++;
        }
        return head;

    }
};