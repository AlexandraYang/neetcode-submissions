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
    vector<int> rightSideView(TreeNode* root) {
        if (!root) {
            return {};
        }

        queue<TreeNode *> q;
        vector<int> ans;
        q.push(root);

        while(!q.empty()) {
            int sz = q.size();

            for (int i = 0; i < sz; ++i) {
                
                TreeNode * tmp = q.front();
                q.pop();


                // keep the last one a.k.a the right most 
                if (i == sz - 1) {
                    ans.push_back(tmp->val);
                }
                

                if (tmp->left) q.push(tmp->left);
                if (tmp->right) q.push(tmp->right);

            }

        }

        return ans;
    }
};
