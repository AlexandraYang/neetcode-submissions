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
    int min_val = 0;
    int idx = 0;
    void dfs(TreeNode* node, int k) {
        if (node == nullptr) {
            return;
        }

        //left 
        dfs(node->left, k);

        //mid
        idx++; //off by one, 1-idx 所以要先加 
        if (idx == k) {
            min_val = node->val;
            //優化! 找到就立刻return 
            return;
        }
        


        //right
        dfs(node->right, k);

         
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        if (root == nullptr) {
            return 0;
        }

        dfs(root, k);
        return min_val;
    }
};
