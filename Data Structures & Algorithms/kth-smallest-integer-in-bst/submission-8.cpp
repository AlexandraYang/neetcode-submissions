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
    bool dfs(TreeNode*node, int k, int & cur_cnt , int &ans) {
        //為空就return
        if (node == nullptr) {
            return false;
        }

        //左
        /*
        「如果左子樹已經找到了答案，
            那我（現在這層）也立刻回傳 true，
            不要再處理我自己，也不要走右子樹。
        */
        if(dfs(node->left, k, cur_cnt, ans)) {
            return true;
        }

        //中 代表left先被訪問過 以後才可以被加入排序
        cur_cnt++;
        if (cur_cnt == k) {
            ans = node->val;
            return true;
        }

        // 右
        if (dfs(node->right, k, cur_cnt, ans)) {
            return true;

        }

        return false;

    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int cur_cnt = 0;
        int ans = 0;
        dfs(root, k, cur_cnt, ans);

        return ans;
    }
};
