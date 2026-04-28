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
    void inorder(TreeNode* node, int k, int&cnt, int & res) {
        if (!node || res != -1) {
            return;
        }

        inorder(node->left, k, cnt, res);

        cnt++;
        if(cnt ==k) {
            res = node->val;
            return;
        }

        inorder(node->right, k, cnt, res);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int cnt = 0;
        int res = -1;

        inorder(root, k, cnt, res);
        return res;
    }
};
