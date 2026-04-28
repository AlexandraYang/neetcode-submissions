class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());// 加上排序！
        vector<int> tmp;
        dfs(candidates, 0, 0, target, tmp);
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
            // 加這行避免重複！
            if (i > start && nums[i] == nums[i - 1]) {
                continue;
            } 
            tmp.push_back(nums[i]);
            dfs(nums, i+1, accum+nums[i], target, tmp);  // i+1 確保每個元素只用一次
            tmp.pop_back();
        }
    }
};
