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
    Node* dfs(Node* node, unordered_map<Node*, Node*>& mp) {
        // 如果 node 是 nullptr
        // 代表沒有 graph
        if (node == nullptr) {
            return nullptr;
        }
        
        //假設node 在mp內，代表clone過
        if (mp.find(node) != mp.end()) {
            
            return mp[node];
        }

        //2. 建立目前 node 的 clone
        Node* clone = new Node(node->val);

        //3. 放進map，把old node 和 clone 對起來
        mp[node] = clone;

        //4. travseral all neighbors
        for (int i = 0; i < node->neighbors.size(); ++i) {

            //把old node的鄰居接到clone 的neighbors
            clone->neighbors.push_back(dfs(node->neighbors[i], mp));
        }

        return clone;
    }
public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> mp; //key = old node, val = new node 

        //我收到一個 old node，就負責把它 clone 完
        return dfs(node, mp);
    }
};
