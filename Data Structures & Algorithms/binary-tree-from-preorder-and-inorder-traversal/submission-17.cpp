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
    unordered_map<int, int> mp;
    TreeNode* build (vector<int>& preorder, vector<int>& inorder, int pre_start, int pre_end, int in_start, int in_end) {
        // preorder 告訴root 
        // inorder 最重要 給區間 
        if (pre_start > pre_end) {
            return nullptr;
        }

        // step1: find root 
        int root_val = preorder[pre_start];

        // step 2: Use root val to create tree 
        TreeNode* root = new TreeNode(root_val);

        int root_idx_in_inorder = mp[root_val];
        int left_tree_size = root_idx_in_inorder - in_start;

        // preorder 中 左 右 
        // inorder  左 中 右 
        root->left = build(preorder, inorder, 
                        pre_start + 1, 
                        pre_start + 1 + left_tree_size -1, //要減1!!!  
                        in_start, 
                        root_idx_in_inorder-1
                        );

        root->right = build(preorder, inorder, 
                        pre_start + 1 + left_tree_size,
                        pre_end,
                        root_idx_in_inorder + 1,
                        in_end
                        );


        return root;

    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        for (int i = 0; i < inorder.size(); ++i) {
            mp[inorder[i]] = i;
        }

        return build(preorder, inorder, 0, n -1, 0, n-1);
    }
};
