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
    bool dfs(TreeNode * node, int max_val, int min_val) {
        if (!node) {
            return true;
        }

        if (node->val >= max_val || node->val <= min_val) {
            return false;
        }

        return dfs(node->left, node->val, min_val) && dfs(node->right, max_val, node->val);
    }

public:
    bool isValidBST(TreeNode* root) {
        return dfs(root, INT_MAX, INT_MIN);
    }
};
