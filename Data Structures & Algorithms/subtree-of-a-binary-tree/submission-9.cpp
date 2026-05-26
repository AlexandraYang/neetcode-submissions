class Solution {
private:
    bool same(TreeNode* a, TreeNode* b) {
        //兩個ptr 不存在 則為true 
        if (!a && !b) {
            return true;
        }

        //2 ptr 其中一個存在 則為真 
        if (!a || !b) {
            return false;
        }

        //假設有值 不對 則為否 
        if (a->val != b->val) {
            return false;
        }


        //繼續loop 左邊跟右邊
        return same(a->left, b->left) &&
               same(a->right, b->right);
    }

public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root) {
            return false;
        }

        //double DFS 
        // 先檢查這個點
        if (same(root, subRoot)) {
            return true;
        }

        // 再往左右找
        return isSubtree(root->left, subRoot) ||
               isSubtree(root->right, subRoot);
    }
};