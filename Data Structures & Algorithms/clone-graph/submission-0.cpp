/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
private:
    unordered_map<Node*, Node*> mp; // key = 原node's address; val = 複製節點's address

    Node* dfs (Node* node) {
        if (!node) {
            return nullptr;
        }

        if (mp.count(node)) {
            return mp[node];
        }

        Node* tmp = new Node(node->val);
        mp[node] = tmp;

        for (Node * nei: node->neighbors) {
            tmp->neighbors.push_back(dfs(nei));
        }

        return tmp;
    }
public:
    Node* cloneGraph(Node* node) {
        return dfs(node);
    }
};
