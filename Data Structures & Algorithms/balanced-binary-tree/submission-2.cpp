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
    int dfs(TreeNode* node) {
        if(!node) {
            return 0;
        }

        int left = dfs(node->left);
        if (left == -1) return -1;

        int right = dfs(node->right);
        if(right == -1) return -1;

        if (abs(left-right) > 1) {
            return -1;
        }
        return 1 + max(right, left); //root 問他下面left right tree 最深是多少'
    }
public:
    bool isBalanced(TreeNode* root) {
        if(!root) {
            return true;
        }

        if(dfs(root) == -1) {
            return false;
        }

        return true;
    }
};
