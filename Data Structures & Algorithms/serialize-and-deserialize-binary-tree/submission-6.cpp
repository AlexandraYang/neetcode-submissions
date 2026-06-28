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
            //假設為空 要方便字串辨識所以用 # 
            vals.push_back("#");
            return;
        }
        //中 
        vals.push_back(to_string(node->val));

        //左 
        build_str(node->left);
        //右 
        build_str(node->right);
        
    }


    //deserialize: vector -> TreeNode 
    TreeNode* dfs(vector<string>&vals, int &idx) {
        if (vals[idx] == "#") {
            idx++;
            return nullptr;
        }

        // vec: [1,2,3,#,#,4,5]
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
        //step1: 先build 
        build_str(root);

        // step 2: 把build完的轉string  
        //          且把數字跟數字之間加 ','號 
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
        
        // step1: 先把string 改回vector 
        //         要處理 null的# ; 數字之間的 ','.
        // string -> vector 
        vector<string> vals;
        string cur;

        for (char c: data) {
            if (c == ',') {
                vals.push_back(cur); 
                cur.clear(); // 2.遇到逗號以後 再handle multi-digits 
            } else {
                cur.push_back(c); // 1. 先build multi-digit 
            }
        }

        
        //如果 input 沒有最後逗號，最後一筆可能不見 
        //所以是檢查cur 有沒最後為空 
        if (!cur.empty()) {
            vals.push_back(cur);
        }

        int idx = 0;
        return dfs(vals, idx);
        


    }
};
















