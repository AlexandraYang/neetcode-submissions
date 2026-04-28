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
    void inorder(TreeNode* node, int k, int &cnt, int & result) {
        if (!node || result != -1) {
            return;
        }


        //因為遞迴就是當下先中斷，要處理完裡面call state 
        // 一路return 上來後 會先
        inorder(node->left, k, cnt, result);

        cnt++;
        if (cnt == k) {
            result = node->val;
            return;
        }

        inorder(node->right, k, cnt, result);

    } 
public:
    int kthSmallest(TreeNode* root, int k) {
        if (!root) {
            return 0;
        }

        int cnt = 0;
        int result = -1;
        inorder(root, k, cnt, result);

        return result;
    }
};
