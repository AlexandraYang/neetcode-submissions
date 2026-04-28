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
    // unordered_map {current_node->new_node}
    unordered_map <Node*, Node*> mp;
    Node* dfs(Node* node) {
        if (node == nullptr) {
            return nullptr;
        }

        if (mp.count(node)) {
          return mp[node];
        }

        //找不到的case
        Node* tmp = new Node(node->val);
        mp[node] = tmp;

          // ⭐ 關鍵：複製所有鄰居
        for (Node* nei: node->neighbors) {
            tmp->neighbors.push_back(dfs(nei));
             // dfs(nei) 會回傳「nei 的 clone 節點」
        }

        return tmp;
    }
public:
    Node* cloneGraph(Node* node) {
       return dfs(node);

    }
};
