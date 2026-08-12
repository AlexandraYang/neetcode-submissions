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
    Node* dfs(Node* node, unordered_map<Node*, Node*> &mp) {
        if (mp.find(node) != mp.end()) {
            return mp[node]; //找到clone過的
        }

        // 1. clone node 
        Node* clone = new Node(node->val);

        // 2. put to mp 
        mp[node] = clone; // old_node -> new_node;

        //3. traverse all neighbors 
        for (int i = 0; i < node->neighbors.size(); ++i) {
            clone->neighbors.push_back(dfs(node->neighbors[i],mp));
        }

        return clone;
    }
public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> mp;

        if (!node) {
            return nullptr;
        }

        return dfs(node, mp);
    }
};
