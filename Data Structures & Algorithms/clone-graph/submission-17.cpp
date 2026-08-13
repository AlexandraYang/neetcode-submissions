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

        // 把目前 node 的「每一條路」都走一次 
        for (int i = 0; i < node->neighbors.size(); ++i) {
            
            // 目前 node 的下一個 node
            Node* neighbor = node->neighbors[i];

            // 走到下一個 node
            // 並取得它的 clone
            Node* cloned_neighbor = dfs(neighbor, mp);

            // 把下一個 node 的 clone
            // 接到目前 clone 的 neighbors
            clone->neighbors.push_back(cloned_neighbor);


            // [更短的寫法]: 從目前 Node 沿著 edge 走到 neighbor → 把 neighbor clone → 回來後把這個 clone neighbor 接到目前 clone 上。
            // clone->neighbors.push_back(dfs(node->neighbors[i],mp));
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
