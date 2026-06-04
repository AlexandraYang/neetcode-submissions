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

        queue<TreeNode *> q;
        
        vector<vector<int>> ans;
        q.push(root);
        while(!q.empty()) {
            int sz = q.size();
            vector<int> seg;
            for (int i = 0; i < sz; ++i) {
                TreeNode* tmp = q.front();
                q.pop();
                
                seg.push_back(tmp->val);

                if (tmp->left) q.push(tmp->left);
                if (tmp->right) q.push(tmp->right);

                
            }

            ans.push_back(seg);
        }

        return ans;
    }
};
