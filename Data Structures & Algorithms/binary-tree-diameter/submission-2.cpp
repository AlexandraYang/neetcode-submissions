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
public:
    int ans = 0;
    int dfs (TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int leftDepth = dfs(root->left);
        int rightDepth = dfs(root->right);

        ans = max(ans, leftDepth + rightDepth); // 易錯!!

        return max(leftDepth, rightDepth) + 1;

    }
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
