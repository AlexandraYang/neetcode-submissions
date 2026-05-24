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
    int maxLen=0;
public:
    int maxDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }

        int left = maxDepth(root->left);
        int right = maxDepth(root->right);

       
        /*
        我的高度 =
        左右子樹較深的高度
        +
        我自己這層 
        */
        return max(right, left) + 1;
        
    }
};
