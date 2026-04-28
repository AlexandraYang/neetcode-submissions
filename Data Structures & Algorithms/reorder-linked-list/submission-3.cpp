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
        //快慢指標找一半後
        //反轉
        // merge

        if (!head || !head->next) {
            return ;
        }

        ListNode* fast = head;
        ListNode* slow = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* prev = nullptr;
        ListNode* cur = slow->next; //6's next 所以就是8 
        while(cur) {
            ListNode* next = cur->next;
            cur->next = prev;

            prev = cur;
            cur = next;
        }

        slow->next = nullptr; //cut l1 off

        ListNode* l1 = head;
        ListNode* l2 = prev;
        ListNode dummy(0);
        ListNode* tmp = &dummy;
        while(l1 ||  l2) {
            if (l1) {
                tmp->next = l1;
                l1 = l1 ->next;
            }
            
            tmp = tmp->next;

            if (l2) {
                tmp->next = l2;
                l2 = l2->next;
            }
            
            tmp = tmp->next;
            
        }

    }
};
