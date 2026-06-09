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
    void dfs(TreeNode* node, int k) {
        if (!node) {
            return;
        }

        
        dfs(node->left, k);

        cnt++;
        if (cnt == k) {
            ans = node->val;
            return ;
        }

        dfs(node->right, k);
        
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        //BST 一定是 左中右 

        if (!root) {
            return ans;
        }
    
        dfs(root, k);

        return ans;
    }
};
