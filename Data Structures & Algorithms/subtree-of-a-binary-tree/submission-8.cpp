class Solution {
private:
    bool same(TreeNode* a, TreeNode* b) {
        if (!a && !b) {
            return true;
        }

        if (!a || !b) {
            return false;
        }

        if (a->val != b->val) {
            return false;
        }

        return same(a->left, b->left) &&
               same(a->right, b->right);
    }

public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root) {
            return false;
        }

        // 先檢查這個點
        if (same(root, subRoot)) {
            return true;
        }

        // 再往左右找
        return isSubtree(root->left, subRoot) ||
               isSubtree(root->right, subRoot);
    }
};