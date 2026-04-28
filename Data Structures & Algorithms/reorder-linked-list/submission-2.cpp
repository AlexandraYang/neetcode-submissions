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
        if (!head || !head->next) return;

        // find middle
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        

        //break and  reverse linked list after middle node
        ListNode* cur = slow->next;
        slow->next = nullptr;

        ListNode* prev = nullptr;
        while (cur) {
            ListNode* post = cur->next; //save
            cur->next = prev; //reverse
            prev = cur;
            cur = post; // forward
        }

        // merge 2 linked list
        // list1 = head
        // list2 = prev
        ListNode* first = head;
        ListNode* second = prev;
        while (second) {
            ListNode* first_next = first->next;
            ListNode* second_next = second->next;

            first->next = second;
            second->next = first_next;

            //forward
            first = first_next;
            second = second_next;

        }

    }
};
