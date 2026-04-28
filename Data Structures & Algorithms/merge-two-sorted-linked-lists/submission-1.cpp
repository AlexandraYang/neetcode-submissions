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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* cur1 = list1;
        ListNode* cur2 = list2;

        ListNode* dummy = new ListNode(-1);
        ListNode* tmp = dummy;

        while (cur1  &&  cur2) {
            if (cur1->val > cur2->val) {
                ListNode *newNode = new ListNode(cur2->val);
                tmp->next = newNode;
                tmp = tmp->next;

                cur2 = cur2->next;
            } else {
                ListNode *newNode = new ListNode(cur1->val);
                tmp->next = newNode;
                tmp = tmp->next;

                cur1 = cur1->next;
            }

        }

        if (cur1 && !cur2) {
            tmp ->next = cur1;
        } else if (!cur1 && cur2) {
            tmp->next = cur2;
        }

        return dummy->next;

    }
};
