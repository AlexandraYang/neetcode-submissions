/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Codec {
private: 
    vector<string> vals;

    void build_str(TreeNode* node) {
        if (!node) {
            vals.push_back("#");
            return;
        }
        
        vals.push_back(to_string(node->val));

        build_str(node->left);
        build_str(node->right);
        
    }

    TreeNode* dfs(vector<string>&vals, int &idx) {
        if (vals[idx] == "#") {
            idx++;
            return nullptr;
        }

        TreeNode* node = new TreeNode(stoi(vals[idx]));
        idx++;

        node->left = dfs(vals, idx);
        node->right = dfs(vals, idx);

        return node;
    }
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        vals.clear();
        build_str(root);

        // vector -> string
        string res;
        for (int i = 0; i < vals.size(); ++i) {
            res += vals[i];
            res += ",";
        }

        return res;
    }

    // Decodes your encoded data to tree.
    //string → must convert to tokens first
    TreeNode* deserialize(string data) {
        if (data.empty()) {
            return nullptr;
        }
        
        // string -> vector 
        vector<string> vals;
        string cur;

        for (char c: data) {
            if (c == ',') {
                vals.push_back(cur);
                cur.clear(); // handle multi-digits 
            } else {
                cur.push_back(c);
            }
        }

        
        //如果 input 沒有最後逗號，最後一筆可能不見 
        if (!cur.empty()) {
            vals.push_back(cur);
        }

        int idx = 0;
        return dfs(vals, idx);
        


    }
};
















