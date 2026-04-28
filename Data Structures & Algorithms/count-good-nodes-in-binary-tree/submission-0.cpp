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
    //解決邏輯就是 DFS下去 然後新node要跟當前maxNode比大小，假設新Node比maxNode大，
    // 那新Node 就是 goodNodes 
    int goodNodes(TreeNode* root) {
        return dfs(root, root->val);
    }

    int dfs(TreeNode* node, int maxVal) {
        if(!node) {
            return 0; // not a goodNode
        }

        int cnt = 0;
        if (node->val >= maxVal) {
            cnt = 1;
        }

        maxVal = max(maxVal, node->val);
        cnt += dfs(node->left, maxVal);
        cnt += dfs(node->right, maxVal);

        return cnt;
    }
};
