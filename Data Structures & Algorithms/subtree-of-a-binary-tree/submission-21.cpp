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
    bool isSame(TreeNode* a, TreeNode* b) {
        if (!a && !b) {
            return true;
        }

        if (!a || !b) {
            return false;
        }

        if (a->val != b->val) {
            return false;
        }


        // [驗證] 判斷兩棵樹是否完全一樣 所以必須左右皆相同 
        return isSame(a->left, b->left) && isSame(a->right, b->right);
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root) {
            return false;
        }

        // //通常假設 subRoot 不為空
        // if (!root || !subRoot) {
        //     return true;
        // }

        // 因為每一個node都有可能是會match的root, 所以這需要分兩層
        if (isSame(root, subRoot)) {
            return true;
        }

        // 在 root 裡面找一棵等於 subRoot 的樹, 左或右擇一成立 即可
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};
