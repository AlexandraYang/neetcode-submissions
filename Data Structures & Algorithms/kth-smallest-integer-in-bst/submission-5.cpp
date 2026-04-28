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
    int ans;
    int cur_cnt;
    bool dfs(TreeNode* node, int k) {
        if(!node) {
            return false;
        }

        if(dfs(node->left, k)) {
            return true;
        }

        cur_cnt++;
        if(cur_cnt == k) {
            ans = node->val;
            return true;
        }

        if(dfs(node->right, k)) {
            return true;
        }
        return 0;
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        cur_cnt = 0;
    
        dfs(root, k);

        return ans;
    }
};
