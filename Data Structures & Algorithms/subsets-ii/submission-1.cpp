class Solution {
private:
    void dfs(vector<vector<int>> &ans, vector<int>& nums, vector<int>& seg, int start) {
        ans.push_back(seg);

        for (int i = start; i < nums.size(); ++i) {
            if (i > start && nums[i] == nums[i-1]) {
                continue;
            }

            seg.push_back(nums[i]);
            dfs(ans, nums, seg, i+1);
            seg.pop_back();
        }

    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> seg;

        sort(nums.begin(), nums.end());
        dfs(ans, nums, seg, 0);
        return ans;
    }
};
