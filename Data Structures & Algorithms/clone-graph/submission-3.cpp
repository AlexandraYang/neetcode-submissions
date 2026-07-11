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
    unordered_map<Node*, Node*> mp; // node's val <--> visited or not 但node-bool 太淺了 要用新舊node
    Node* dfs(Node* node) {
        // 已經 clone 過
        if (mp.count(node)) {
            return mp[node];
        }
        // 建立 clone
        Node * new_node = new Node(node->val);
        mp[node] = new_node;


        // 遍歷 neighbors
        for (int i = 0; i < node->neighbors.size() ; ++i) {
            // dfs(node->neighbors[i]); // 錯誤的寫法 dfs但neighbor 沒填值 
            new_node->neighbors.push_back(dfs(node->neighbors[i]));
        }

        //等於告訴未來遇到這個 old node 的 DFS：
        //「不要再創建新的了，之前那個 clone 在這裡，直接拿去連。」
        return new_node;
    }

public:
    Node* cloneGraph(Node* node) {
        if (!node) {
            return nullptr;
        }


        //驅動第一次dfs !
        return dfs(node);

    }
};
