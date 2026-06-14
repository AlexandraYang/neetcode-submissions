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
    unordered_map<int, int> mp; // val, idx 
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int pre_start, int pre_end, int in_start, int in_end) {
        if (pre_start > pre_end) {
            //代表沒有root了 
            return nullptr;
        }

        // step 1: 先找root val from preorder 
        int root_val = preorder[pre_start];

        // step 1.1: 用這個root 去init 一個樹
        TreeNode * root = new TreeNode(root_val);

        // step 2: root val當key, 去找inorder的idx 
        // inorder = 左 中 右 
        int root_idx_in_inorder = mp[root_val];

        // step 3: 找到左樹size 
        int left_tree_size =  root_idx_in_inorder - in_start;

        //preorder = 中左右 
        //inorder = 左中右 
        root-> left = build(
            preorder,
            inorder,

            pre_start +1,
            pre_start+1 + left_tree_size -1,
            
            in_start,
            root_idx_in_inorder-1
            
        );


        //preorder = 中左右 
        //inorder = 左中右 
        root-> right = build(
            preorder,
            inorder,

            pre_start+1 + left_tree_size,
            pre_end,
            
            root_idx_in_inorder+1,
            in_end
            
        );

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        // preorder 告訴我root 
        // inorder 告訴我左右樹區間 為了快速查找必須建立hashmap 
        for (int i = 0; i < inorder.size(); ++i) {
            mp[inorder[i]] = i;
        }

        return build(preorder, inorder, 0, n-1, 0, n-1);
    }
};
