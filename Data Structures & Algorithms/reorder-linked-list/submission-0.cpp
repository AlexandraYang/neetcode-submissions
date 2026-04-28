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
        // 
        if (head == nullptr) {
            return;
        }

         // Step 1: 找到链表中点
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        //step 2: divide linked list
        ListNode* head2 = slow->next;
        slow->next = nullptr;

        //step 3: revert linked list
        head2 = reverseList(head2);

        // step4: merge 2 linked list
        ListNode* p1 = head;
        ListNode* p2 = head2;
        while (p2) {
            ListNode* p1_next = p1->next;
            ListNode* p2_next = p2->next;

            p1->next = p2;
            p2->next = p1_next;

            p1 = p1_next;
            p2 = p2_next;
        }
    }

private:
    ListNode* reverseList(ListNode* src) {
        if (src == nullptr) {
            return src;
        }
        
        ListNode* prev = nullptr;
        ListNode* cur = src;

        while (cur) {
            ListNode* tmp = cur->next;
            cur->next = prev;

            prev = cur;
            cur = tmp;
        }

        return prev;
    }
};
