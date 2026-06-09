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
    int dfs(TreeNode* node, int max_val) {
        //一路走下去發現沒有人比他大 他就是good node
        int cnt = 0;
        
        if (!node) {
            return cnt;
        }

        if (node->val >= max_val) {
            cnt = 1;
        }

        max_val = max(node->val, max_val);

        

        cnt += dfs(node->left, max_val);
        cnt += dfs(node->right, max_val);

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
