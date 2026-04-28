class Solution {
    /*
Input: 
nums = [2,5,6,9] 
target = 9

Output: [[2,2,5],[9]]
    */
private:
    void dfs(vector<int>& nums, vector<vector<int>> &ans, vector<int>& seg, int target, int accum, int start) {
        if (target == accum) {
            ans.push_back(seg);
            return;
        }

        for (int i = start; i < nums.size(); ++i) {
            if (accum + nums[i] > target) {
                continue;
            }
            seg.push_back(nums[i]);
            dfs(nums, ans, seg, target, nums[i]+accum, i);

            // accum -= nums[i];
            seg.pop_back();
        }

    }

public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> seg;
        // vector<bool> used (nums.size(), false);

        dfs(nums, ans, seg, target, 0, 0);

        return ans;
    }
};
