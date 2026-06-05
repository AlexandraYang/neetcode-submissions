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

    int dfs(TreeNode* node, int mx) {
        if (!node) {
            return 0;
        } 

        int cnt = 0;
        if (node->val >= mx) {
            cnt = 1;
        } 

        mx = max(mx, node->val);
 
        //先左 再右
        cnt += dfs(node->left, mx);
        cnt += dfs(node->right, mx);

        return cnt;
    }
public:
    int goodNodes(TreeNode* root) {
        if (!root) {
            return 0;
        }

        return dfs(root, root->val);

    }
};
