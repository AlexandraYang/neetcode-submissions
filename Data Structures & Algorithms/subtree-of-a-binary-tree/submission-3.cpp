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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // case 1: 假設左右node都為空
        if (!p && !q) {
            return true;
        }

        // case 2: 假設有任一node 不存在 則為空
        if (!p || !q) {
            return false;
        }

        // case 3: 若左node 值 != 右node值，則須return false
        if (p->val != q->val) {
            return false;
        }

        // 比較繼續下去 往右跟往左
        return isSameTree(p->right, q->right) && isSameTree(p->left, q->left);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // case 1: 若root empty, 則subRoot 必不是他的子樹
        if (!root) {
            return false;
        }    

        // case 2: root 和subRoot, 完全一樣則回傳true
        if (isSameTree(root, subRoot)) {
            return true;
        }

        // case 3: 否則繼續recursive的去找；root 的任一子樹是 subRoot，就算成立
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};
