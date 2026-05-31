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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while (root) {
            if (root-> val > q->val && root->val > p->val) {
                //假設root 都很大的話，就要往左走 
                root = root->left;
            } else if (root->val < q->val && root->val < p->val) {
                //假設root 太小 那就root 要往右走 
                root = root->right;
            } else {
                return root;
            }
        }

        return nullptr;
    }
};
