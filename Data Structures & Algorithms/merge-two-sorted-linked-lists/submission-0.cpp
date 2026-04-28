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
        ListNode* ans = new ListNode(0);
        ListNode*ptr = ans;
        while (list1 != nullptr && list2 != nullptr ) {
            if (list1->val > list2->val) {
                ListNode* tmp = new ListNode(list2->val);
                ptr->next = tmp;
                list2 = list2->next;
            } else {
                ListNode* tmp = new ListNode(list1->val);
                ptr->next = tmp;
                list1 = list1->next;
            }
            ptr = ptr->next;
        }

        if (list1) {
            ptr->next = list1;
        } else {
            ptr->next = list2;
        }

        return ans->next;
        
    }
};
