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
        if (!head || !head->next) {
            return; // 链表为空或只有一个节点，无需重排
        }

        // Step 1: 找到链表中点
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: 分割链表
        ListNode* head2 = slow->next; // head2 是后半部分链表的头节点
        slow->next = nullptr; // 将链表从中间断开

        // Step 3: 逆序后半部分
        head2 = reverseList(head2); // 逆序后的后半部分链表

        // Step 4: 交替合并两个链表
        ListNode* p1 = head; // 前半部分链表的当前指针
        ListNode* p2 = head2; // 后半部分链表的当前指针

        while (p2) { // 当后半部分链表还有节点时进行合并
            ListNode* next1 = p1->next; // 保存前半部分当前节点的下一个节点
            ListNode* next2 = p2->next; // 保存后半部分当前节点的下一个节点

            p1->next = p2; // 前半部分当前节点指向后半部分当前节点
            p2->next = next1; // 后半部分当前节点指向前半部分之前保存的下一个节点

            p1 = next1; // 移动前半部分指针
            p2 = next2; // 移动后半部分指针
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
