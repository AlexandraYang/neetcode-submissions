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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* tmp = head;
        for (int i = 0; i < k; i++) {
            if (tmp == nullptr) {
                //檢查是否至少三個
                return head;
            }

            tmp = tmp->next;
        }

        ListNode* prev = nullptr;
        ListNode* cur = head;
        ListNode* next = nullptr;

        for (int i = 0; i < k; i++) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next; 
        }

        head->next = reverseKGroup(cur, k);

        return prev;
    }
};
