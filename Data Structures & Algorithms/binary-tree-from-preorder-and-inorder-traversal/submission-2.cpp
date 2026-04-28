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

class Solution {
private:
    unordered_map<int, int> mp; //val -> idx
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int pre_start, int pre_end, int in_start, int in_end) {

        if (pre_start > pre_end || in_start > in_end) {
            return nullptr;
        }

        int root_val = preorder[pre_start];
        TreeNode* root = new TreeNode(root_val);

        int left_len_in_order = mp[root_val] - in_start;
        root->left = build(preorder, inorder, 
            pre_start +1, 
            pre_start + left_len_in_order,
            in_start, 
            mp[root_val] -1);

        root->right = build(preorder, inorder, 
            pre_start + left_len_in_order + 1, 
            pre_end,
            mp[root_val] +1,
            in_end);

        return root;

    }
public:
// preorder是給中左右  第一個是root
// inorder 是左中右  找出左樹的數字有幾個
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // pre-order: mid - left - right 
        //             1 2       3 4
        // in-order: left - mid - right
        //            2    1      3   4 
        

        //先建立inordered map, key -> idx
        for(int i = 0; i < inorder.size(); ++i) {
            mp[inorder[i]] = i;
        }

        return build(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);

    }
};
