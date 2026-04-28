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
    int pre_idx = 0; //當前root 在preorder_list下的位置
    unordered_map<int, int> inorder_pos;// inorfer 對應位置
public:
    TreeNode* dfs(vector<int>& preorder, int left, int right) {
        if (left > right) {
            return nullptr;
        }

        // 取 preorder 當前的值作為 root
        int root_val = preorder[pre_idx++]; // 取完才++的
        TreeNode* root = new TreeNode(root_val);

        int mid = inorder_pos[root_val];

// 左  中  又
// 建立左子樹（inorder 左半）
        root->left = dfs(preorder, left, mid -1);
        root->right = dfs(preorder, mid + 1, right);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); ++i) {
            inorder_pos[inorder[i]] = i; // key是inorder內的值；val 是值的index
        }

        return dfs(preorder, 0, inorder.size() - 1);
    }
};
