class Solution {
private:
    void dfs(vector<int>& nums, vector<int>& seg, vector<vector<int>>& ans, int start) {
        ans.push_back(seg);

        for (int i = start; i < nums.size(); ++i) {
            seg.push_back(nums[i]);
            dfs(nums, seg, ans, i+1);
            seg.pop_back();
        } 
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> seg;
        vector<vector<int>> ans;

        dfs(nums, seg, ans, 0);

        return ans;
    }
};
