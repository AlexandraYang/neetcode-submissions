class Solution {
private:
    void dfs(vector<int>& nums, int start, int accum, int target, vector<int> & seg) {
        if (accum == target) {
            ans.push_back(seg);
            return;
        }

        if (accum > target) {
            return;
        }

        for (int i = start; i < nums.size(); ++i) {
            seg.push_back(nums[i]);
            dfs(nums, i, accum + nums[i], target, seg);
            seg.pop_back();
        }

    }
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
       
        vector<int> seg;
        dfs(nums, 0, 0, target, seg);

        return ans;
    }
};
