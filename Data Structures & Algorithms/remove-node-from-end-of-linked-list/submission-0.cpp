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
        //Step 1: 建立dummy 因為方便處理第一個node 是要刪除的
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        //Step2: 設定fast and slow 都從dummy開始
        ListNode* fast = dummy;
        ListNode* slow = dummy;

        //Step 3: 讓fast 先走n步
        for (int i = 0; i < n ; ++i) {
            fast = fast->next;
        }

        //step4: fast 往前走直到nullptr 同時讓 slow 停在「要刪除節點的前一個節點」
        /*
        如果你寫的是 while (fast != nullptr) 呢？
        那麼 fast 就會走到 nullptr 才停，這時候 slow 就會走過頭，
        變成指向要刪除的節點本身，而不是它的前一個節點。
        你就無法寫 slow->next = ...，因為你想刪除的是 slow 自己，這樣就無法處理。
        */
        while (fast->next != nullptr) {
            fast = fast->next;// 讓 fast 指針走到「最後一個節點」
            slow = slow->next; //此時 slow 正好就會停在「要被刪掉的節點的前一個節點」
        }

        //step5: 刪除slow後面的那個點
        ListNode* toDelete = slow->next;
        slow->next = slow->next->next;
        delete toDelete;

        //step6: return new head
        return dummy->next;
    }
};
