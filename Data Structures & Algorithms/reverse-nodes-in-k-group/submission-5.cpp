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
        // step 0: defense
        if (!head || k == 1) {
            return head;
        }
        // step 1: count the length
        int len = 0;
        ListNode* temp = head;
        while (temp) {
            temp = temp->next;
            len ++;
        }
        // step 2: in K loop, do head-insert reverse
        ListNode dummy(0);
        dummy.next = head;
        ListNode*prev = &dummy;

        while (len >= k) {
            ListNode* curr = prev->next;
            ListNode* next = curr->next;

            for (int i = 1; i < k; ++i) {
                //  D   1   2   3   4   5
                // (p)  (c) (n)

 
                curr->next = next->next;//先切 1-> 3
                next->next = prev->next; // 2->1
                prev->next =  next;// D->2
                //  D  2    1    3    4
                // (p) (n)  (c)  
                next = curr->next; // make next(2) to be next(3)
                //  D  2    1    3    4
                // (p)     (c)   (n) 
            }

            prev = curr;
            len = len-k;
        }

        
        // step 3: return dummy
        return dummy.next;
    }
};
