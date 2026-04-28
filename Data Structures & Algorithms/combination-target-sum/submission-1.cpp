class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> tmp;
        dfs(nums, 0, 0, target, tmp);
        return ans;
    }

private:
    void dfs(vector<int>& nums, int start, int accum, int target, vector<int>& tmp) {
        if (accum == target) {
            ans.push_back(tmp);
            return;
        }

        if (accum > target) {
            return;
        }


        for (int i = start ; i < nums.size(); ++i) {
            tmp.push_back(nums[i]);
            dfs(nums, i, accum+nums[i], target, tmp); //會有重複 所以不i+1
            tmp.pop_back();
        }
    }
};
