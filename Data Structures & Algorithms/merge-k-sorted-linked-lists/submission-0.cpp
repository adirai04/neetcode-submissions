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
    typedef pair<int, ListNode*> P;
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<P, vector<P>, greater<P>> pq;

        for (auto head : lists) {
            if (head) {
                pq.push({head->val, head});
            }
        }

        ListNode* dummy = new ListNode(-1);
        ListNode* temp  = dummy;

        while (!pq.empty()) {
            auto node = pq.top().second;
            pq.pop();

            temp->next = node;
            temp = temp->next;

            if (node->next) {
                pq.push({node->next->val, node->next});
            }
        }

        return dummy->next;
    }
};
