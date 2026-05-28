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
    int maxLen = 0;
    int dfs(TreeNode *node) {
        if (!node) {
            return 0;
        }

        int left = dfs(node->left);
        int right = dfs(node->right);

        maxLen = max(maxLen, left+right);

        return max(left, right) +1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);

        return maxLen;
    }
};
