class Solution {
private:
    void dfs(vector<vector<int>>& ans, vector<int>& nums, vector<int>& seg, vector<bool>& used) {
        // 剪枝條件
        if (seg.size() == nums.size()) {
            ans.push_back(seg);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (used[i]) {
                // if used, we skip it.
                continue;
            }

            used[i] = true;
            seg.push_back(nums[i]);

            dfs(ans, nums, seg, used);

            used[i] = false;
            seg.pop_back();
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        // step 1: bool to record used or not
        // step 2: backtracking
        // step 3: return ans

        vector<vector<int>> ans;
        vector<int> seg;
        vector<bool> used(nums.size(), false);

        dfs(ans, nums, seg, used);

        return ans;
    }
};
