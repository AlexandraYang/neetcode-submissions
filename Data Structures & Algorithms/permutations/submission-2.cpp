class Solution {
private:
    void dfs(vector<vector<int>>& ans, vector<int> & tmp, vector<int>& nums,vector<bool>& used ) {
        if (tmp.size() == nums.size()) {
            ans.push_back(tmp);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (used[i] == true) {
                continue;
            }

            tmp.push_back(nums[i]);
            used[i] = true;
            dfs(ans, tmp, nums, used);
            tmp.pop_back();
            used[i] = false;
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        //因為是任選 所以我用used[i]去比對
        vector<vector<int>> ans;
        vector<int> tmp;
        vector<bool> used(nums.size(), false);

        dfs(ans, tmp, nums, used);

        return ans;
    }
};
