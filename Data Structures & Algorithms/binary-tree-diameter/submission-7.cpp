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
    int cnt;
    int dfs(TreeNode* node) {
        if(!node) {
            return 0;
        }

        int right = dfs(node->right);
        int left = dfs(node->left);

        cnt = max(cnt, right+left);
       
       return 1 + max(right, left);

    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
       if(!root) {
        return 0;
       }
        cnt = 0;

       //爸問我 但我只能回傳我下面左右最深處 否則會變成Y型
       // 我需要自己跟全域變數比較
       dfs(root);
       return cnt;
    
    }
};
