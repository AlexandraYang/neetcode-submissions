/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map <Node*, Node*> old2New;
        if (!head) {
            return head;
        }

        // step 1: loop 一次建立node
        Node* cur = head;
        while (cur) {
            old2New[cur] = new Node(cur->val);
            cur = cur->next;
        }
        // step 2: loop 第二次去建立link
        cur = head;
        while (cur) {
            old2New[cur]->next = old2New[cur->next];
            old2New[cur]->random = old2New[cur->random];
            cur = cur->next;
        }

        return old2New[head];
    }
};
