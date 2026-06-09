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
    bool dfs(TreeNode* node, int mx, int mn) {
        if (!node) {
            return true;
        }

        if (node->val >= mx || node->val <= mn) {
            return false;
        }

        return dfs(node->left, node->val, mn) && dfs(node->right, mx, node->val);
    }
public:
    bool isValidBST(TreeNode* root) {
       if (!root) {
        return true;
       }

        return dfs(root, INT_MAX, INT_MIN);

    }
};
