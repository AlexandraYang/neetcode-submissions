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
        // -----------------------------
        // STEP 1: 確認是否還有 k 個節點
        // -----------------------------
        ListNode* node = head;
        for (int i =0; i < k; ++i) {
            if (!node) {
                return head; //不夠K個，不需要反轉
            }

            node = node->next;
        }

        // -----------------------------
        // STEP 2: 反轉這 k 個節點
        // -----------------------------
        ListNode* prev = nullptr;
        ListNode* cur = head;
        ListNode* next = nullptr;
        for (int i = 0; i< k; ++i) {
            next = cur->next;//暫存下一個節點
            cur->next = prev;//指向前一個節點（反轉）
            prev = cur; // prev 往前一步（向右移）
            cur = next;//curr 移動到下一個節點
        }

        // 當前 curr 是下一組的開頭
        // prev 是這一組新的頭
        // head 是反轉前的頭，現在變成尾巴

        // -----------------------------
        // STEP 3: 遞迴反轉後面的部分
        // -----------------------------
        head->next = reverseKGroup(cur, k);

         // -----------------------------
        // STEP 4: 回傳新的頭節點（prev）
        // -----------------------------
        return prev;

    }
};
