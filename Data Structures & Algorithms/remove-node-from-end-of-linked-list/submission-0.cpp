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
        auto node = head;
        while (n > 0) {
            node = node->next;
            n--;
        }

        if (node == NULL) return head->next;

        auto curr = head;
        while (node->next) {
            curr = curr->next;
            node = node->next;
        }

        curr->next = curr->next->next;
        
        return head;
    }
};
