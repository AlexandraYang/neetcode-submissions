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
    unordered_map<Node*, Node*> mp;
    Node* dfs(Node * node) {
        // step1: 
        if (!node) {
            return nullptr;
        }

        if (mp.count(node)) {
            return mp[node];
        }
        
        //全新的 
        Node* new_node = new Node(node->val);
        mp[node] = new_node;
        // step2: 
        for (int i = 0; i < node->neighbors.size(); i++) {
            new_node->neighbors.push_back(dfs(node->neighbors[i]));
        }   
        
        return mp[node];
    }
public:
    Node* cloneGraph(Node* node) {

        //因為是clone 全新的 所以unordered_map 是 <Node*, Node*>
        // 所以dfs 假設遇到創建過的 就可以直接return new Node 

        return dfs(node);
    }
};
