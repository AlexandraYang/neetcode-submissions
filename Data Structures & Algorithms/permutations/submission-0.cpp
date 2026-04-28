class Solution {
private:
    void dfs(vector<int>& nums, vector<int>& seg, vector<vector<int>>& ans, vector<bool>& used) {
        if (seg.size() == nums.size()) {
            ans.push_back(seg);
            return;
        }

        for (int i =0; i < nums.size(); ++i) {
            if (used[i]) {
                continue;
            }

            used[i] = true;
            seg.push_back(nums[i]);

            dfs(nums, seg, ans, used);

            seg.pop_back();
            used[i] = false;
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> seg;
        vector<bool> used(nums.size(), false);

        dfs(nums, seg, ans, used);

        return ans;
    }
};
