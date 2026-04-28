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
    unordered_map <int, int> mp; // val -> idx in inorder
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int pre_start, int pre_end, int in_start, int in_end) {
        if (pre_start > pre_end || in_start > in_end) {
            return nullptr;
        }

        // 找root in prorder
        int root_val = preorder[pre_start];
        int root_idx_in_inorder = mp[root_val];

        TreeNode* root = new TreeNode(root_val);
        int left_tree_size = root_idx_in_inorder - in_start;
        root->left = build(preorder, inorder, pre_start+1, pre_start+left_tree_size, in_start, in_start + left_tree_size -1);
        root->right = build(preorder, inorder, pre_start+1+left_tree_size, pre_end, in_start + left_tree_size + 1, in_end);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        /*
        Input: preorder = [1,2,3,4],  中左右
        inorder = [2,1,3,4] 左中右

Output: [1,2,3,null,null,null,4]
        */

        for (int i =0; i < inorder.size(); ++i) {
            mp[inorder[i]] = i;
        }

        return build(preorder, inorder, 0, preorder.size() -1, 0, inorder.size() -1);

    }
};
