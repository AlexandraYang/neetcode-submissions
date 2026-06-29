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
    vector<string> ans;
    TreeNode * ans_root;
    void build_vec(TreeNode* node) {
        if (!node) {
            ans.push_back("#");
            return;
        }

        //mid 
        ans.push_back(to_string(node->val));

        //left 
        build_vec(node->left);
        
        //right
        build_vec(node->right);
        
    }

    TreeNode* build_tree(vector<string> &tmp, int & idx) {
        //vector -> TreeNode 
        if (idx == tmp.size() || tmp[idx] == "#") {
            idx++;
            return nullptr;
        }

        TreeNode * root  = new TreeNode(stoi(tmp[idx]));
        idx++;

        root->left = build_tree(tmp, idx);
        root->right = build_tree(tmp, idx);

        return root;

    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) {
            return "";
        }

        // init vector
        ans.clear();

        // tree->vector        
        build_vec(root);

        // vector -> string
        string result = "";
        for(int i = 0; i <ans.size(); ++i) {
            result += ans[i];
            if (i != ans.size()-1) {
                result += ",";
            }
            
            
        }

        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) {
            return nullptr;

        }

        // 34,#,3,#,135,#
        // string -> vector 
        string cur_val;
        vector<string> tmp;
        for (int i = 0; i < data.size(); ++i) {
            if (data[i] == ',') {
                tmp.push_back(cur_val);
                cur_val.clear();
            } else  {
                cur_val.push_back(data[i]);
            }
        }

        // string check 
        if (!cur_val.empty()) {
            tmp.push_back(cur_val);
        }
        //vector->TreeNode
        // must use dfs() to build, cannot iterate loop
        int idx = 0;
        
        return build_tree(tmp, idx);


    }
};
