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
    bool ok = true;
    int dfs(TreeNode* node) {
        if(!node) {
            return 0;
        }

        int left = dfs(node->left);
        int right = dfs(node->right);

        if (abs(left-right) > 1) {
            ok = false;
        }

        /* 目前節點的高度 = 左右子樹較高的那一邊 + 自己這一層*/
        return max(left, right) +1;
    }
public:
    bool isBalanced(TreeNode* root) {
        dfs(root);
        return ok;
    }
};
