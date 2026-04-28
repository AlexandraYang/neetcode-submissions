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
        if (!head || head->next == nullptr) {
            return head;
        }

        ListNode* cur = head;
        ListNode* prev = nullptr;
        while (cur) { // iterate every one
            ListNode * post = cur->next; // save

            cur->next = prev;

            prev = cur;
            cur = post;

        }

        return prev;

    }
};
