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
    int dfs(TreeNode* node, int max_so_far) {
        if(!node) {
            return 0;
        }

        int cnt = 0;
        if(node->val >= max_so_far) {
            cnt = 1;
            max_so_far = node->val;
        }

        cnt += dfs(node->left, max_so_far);
        cnt += dfs(node->right, max_so_far);

        return cnt;
    }
public:

    int goodNodes(TreeNode* root) {
        if(!root) {
            return 0;
        }

        return dfs(root, root->val);
    }
};
