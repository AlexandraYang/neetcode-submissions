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
    bool res = true;
    bool isBalanced(TreeNode* root) {
        maxdp(root);
        return res;
    }

    int maxdp(TreeNode* root) {
        if (!root || !res) {
            return 0;
        }

        int left = maxdp(root->left);
        int right = maxdp(root->right);

        if (abs(left-right) > 1) {
            res = false;
            return 0;
        }

        return max(left, right) + 1;
    }
};
