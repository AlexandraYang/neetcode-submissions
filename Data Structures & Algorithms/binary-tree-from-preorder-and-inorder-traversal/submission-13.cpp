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
    unordered_map<int,int> inorderIdxMap;

    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int pre_start, int pre_end, int in_start,int in_end) {
        
        //沒有節點 
        if (pre_start > pre_end) {
            return nullptr;
        }

        int root_val_in_pre = preorder[pre_start];
        TreeNode* root = new TreeNode(root_val_in_pre);

        int root_idx_in_inorder = inorderIdxMap[root_val_in_pre];

        int left_tree_size =  root_idx_in_inorder - in_start;// from preorder

        root->left = build(preorder, 
                            inorder, 
                            pre_start +1,
                            pre_start + left_tree_size, //好怪哦 為何不用 pre_start + left_tree_size+1 去避開第一個root

                            in_start,
                            root_idx_in_inorder -1
                            
                            ); 
        root->right = build(preorder,
                        inorder,
                        pre_start+left_tree_size+1, // 這個1 是root的對吧 
                        pre_end,

                        root_idx_in_inorder+1,
                        in_end 
                        );

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();

        for (int i = 0; i < n ; i++) {
            inorderIdxMap[inorder[i]] = i;
        }

        return build(preorder, inorder, 0, n-1, 0, n-1);
    }
};
