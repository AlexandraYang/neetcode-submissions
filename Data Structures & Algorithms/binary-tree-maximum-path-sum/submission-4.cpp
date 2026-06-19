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
    int max_path_val;
    int buildPath(TreeNode* node) {
        if (!node) {
            return 0;
        }

        int left = max(0, max(0, buildPath(node->left)));
        int right = max(0, max(0, buildPath(node->right)));
        max_path_val = max(max_path_val, node->val + left + right);
        return node->val + max(left, right);
    }
public:
    
    int maxPathSum(TreeNode* root) {
        max_path_val = INT_MIN;

        buildPath(root);

        return max_path_val;
    }
};
