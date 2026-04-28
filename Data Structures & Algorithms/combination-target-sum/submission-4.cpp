class Solution {
private:
    void dfs(vector<vector<int>>& ans, vector<int>& seg, int accum, int target, vector<int>& nums, int start) {
        if (target == accum) {
            ans.push_back(seg);
            return;
        }

        for (int i = start; i < nums.size(); ++i) {
            // pruning
            if (accum > target) {
                return;
            }

            seg.push_back(nums[i]);
            dfs(ans, seg, accum + nums[i], target, nums, i);
            seg.pop_back();
        }

    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        /*
        1. 需要有accum
        2. 每次 dfs下去是nums[i]+accum
        3. 剪枝條件 target == accum or loop 時 發現加進去後 accum > target
        */
        vector<vector<int>> ans;
        vector<int> seg;

        dfs(ans, seg, 0, target, nums, 0);

        return ans;
    }
};
