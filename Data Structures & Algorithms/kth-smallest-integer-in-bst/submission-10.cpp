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
    int ans; //用來存第K個小
    bool dfs(TreeNode* root, int k, int &cur_cnt) {
        if (!root) {
            return false;
        }

        if (dfs(root->left, k, cur_cnt)) {
            return true;
        }

        cur_cnt++;
        if (cur_cnt == k) {
            ans = root->val;
            return true; //提早結束
        }

         if (dfs(root->right, k, cur_cnt)) {
            return true;
        }

        return false;
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        if (!root) {
            return 0;
        }
        ans = 0;
        int cur_cnt = 0;

        dfs(root, k, cur_cnt);
        return ans;
    }
};
