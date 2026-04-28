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
    int max_diameter = 0;
    int dfs(TreeNode* node) {
        if(!node) {
            return 0;
        }

        int left = dfs(node->left);
        int right = dfs(node->right);

        max_diameter = max(left+right, max_diameter);

        return 1 + max(left, right);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);

        return max_diameter;
    }
};
