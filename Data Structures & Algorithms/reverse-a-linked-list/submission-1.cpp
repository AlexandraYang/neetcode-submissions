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
    ListNode* reverseList(ListNode* head) {
        // 1. check bound case
        if (!head || head->next == nullptr) {
            return head;
        }

        ListNode * cur = head;
        ListNode * prev = nullptr;
        while (cur != nullptr) {
            // save tmp
            ListNode * post = cur->next;

            //reverse
            cur->next = prev;

            // forward
            prev = cur;
            cur = post;
        }

        return prev;
    }
};
