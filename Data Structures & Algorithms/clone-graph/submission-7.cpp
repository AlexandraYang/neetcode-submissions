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
    unordered_map <Node *, Node*> mp;
    Node* dfs(Node* node) {
        if (!node) {
            return nullptr;
        }


        if (mp.count(node)) {
            return mp[node];
        }

        Node * new_node = new Node(node->val);
        mp[node] = new_node;

        for (int i = 0; i < node->neighbors.size(); ++i) {
            new_node->neighbors.push_back(dfs(node->neighbors[i]));
        }

        return new_node;
    }
public:
    Node* cloneGraph(Node* node) {
        if (!node) {
            return nullptr;
        }
        return dfs(node);
    }
};
