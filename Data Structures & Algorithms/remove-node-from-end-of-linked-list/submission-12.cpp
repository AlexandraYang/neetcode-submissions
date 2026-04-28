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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head) {
            return nullptr;
        }

        ListNode dummy(0);
        dummy.next = head;
        ListNode* fast = &dummy;
        ListNode* slow = &dummy;
        //因為從dummy出發, 所以要多走一步，故 '<= n'
        for (int i = 0; i <= n ; ++i) {
            fast = fast->next;
        }
        //[1,2,3,4]
        //   s   f
        //
        //[1,2,3,4,5]
        //     s   f
        // s->next is the node be deleted. 
        
        while(fast) {
            //兩個一起走
            slow = slow->next;
            fast = fast->next;
        }
        
        slow->next = slow->next->next;

        return dummy.next;

    }
};
