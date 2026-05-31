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
    bool sameTree(TreeNode* a, TreeNode* b) {
        if (!a && !b) {
            return true;
        }

        if (!a || !b) {
            return false;
        }

        if (a->val != b->val) {
            return false;
        }

        return sameTree(a->left, b->left) && sameTree(a->right, b->right);
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root ) {
            return false;
        }

        if(!subRoot) {
            //空集合是任何人的subTree 
            return false;
        }

        // double DFS 
        // 第一層 
        if(sameTree(root, subRoot)) {
            return true;
        }
        
        //當前節點不對 → 去左邊找 OR 去右邊找
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};
