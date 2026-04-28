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
        unordered_map<Node*, Node*> old2New; //
        if (!head) {
            return nullptr;
        }

        // 第一步：建立所有新節點
        Node* curr = head;
        while (curr) {
            old2New[curr] = new Node(curr->val);
            curr = curr->next;
        }

        // 第二步：設置 next 和 random
        curr = head;
        while(curr) {
            old2New[curr]->next = old2New[curr->next];
            old2New[curr]->random = old2New[curr->random];

            curr = curr->next;
        }

        return old2New[head];
    }
};
