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
    int depth;
    int max_len;
public:
    int maxDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }

       
        int right = maxDepth(root->right);
        int left = maxDepth(root->left);
       
        
        return max(left, right) +1;
    }
};
