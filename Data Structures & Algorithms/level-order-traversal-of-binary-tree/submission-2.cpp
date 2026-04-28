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
        queue<TreeNode*> q;

        if (!root) {
            return {};
        }

        vector<vector<int>> ans;

        q.push(root);
        while(!q.empty()) {
            int q_size = q.size();
            vector<int> tmp;
            
            for (int i = 0; i < q_size; ++i) {
                TreeNode* cur = q.front();
                q.pop();

                tmp.push_back(cur->val);
                if (cur->left) {
                    q.push(cur->left);
                }

                if (cur->right) {
                    q.push(cur->right);
                }
            }
            ans.push_back(tmp);
        }
        return ans;

    }
};
