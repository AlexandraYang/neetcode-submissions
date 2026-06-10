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
    int ans = -1;
    int cnt = 0;
    void dfs(TreeNode * node, int k ) {
        if (!node) {
            return;
        }

        dfs(node->left, k);

        cnt++;
        if (k == cnt) {
            ans = node->val;
        }

        dfs(node->right, k);

    }
public:
    int kthSmallest(TreeNode* root, int k) {
        dfs(root, k);

        return ans;
    }
};
