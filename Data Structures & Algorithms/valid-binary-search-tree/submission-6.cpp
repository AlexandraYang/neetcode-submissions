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
    bool isValidBST(TreeNode* root) {
        return dfs(root, LONG_MIN, LONG_MAX);
    }

    bool dfs(TreeNode* node, long  low, long  high) { // boundary
        if (!node) return true;

        if (node->val <= low || node->val >= high) {
            return false;
        }

        //如果是一開始的左樹往左走，那基本上是上線的boundary 被限制；因為必須小於node
        return dfs(node->left, low, node->val) && 
        // 但反之若是 是root的樹右側，則
        dfs(node->right,  node->val, high );
    }
};
