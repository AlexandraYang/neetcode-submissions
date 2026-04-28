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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) {
            return {};
        }

        vector<vector<int>> ans;
        queue<TreeNode* > q;
        q.push(root);
        while(!q.empty()) {
            int q_size = q.size();
            vector<int> level;
            for (int i = 0; i < q_size; ++i) {
                // q size 有多少個就要pop 多少次!
                TreeNode* cur = q.front();
                q.pop();

                level.push_back(cur->val);
                if (cur->left) {
                    q.push(cur->left);
                }

                if (cur->right) {
                    q.push(cur->right);
                }
            }

            ans.push_back(level);
        }

        return ans;
    }
};
