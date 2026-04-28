class Solution {
private:
    void dfs(const vector<int>& nums, int start, vector<int>& segment, vector<vector<int>>& ans) {
        ans.push_back(segment);

        for (int i = start; i < nums.size(); ++i) {
            segment.push_back(nums[i]);
            dfs(nums, i+1, segment, ans);
            segment.pop_back();
        }
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector <int> segment;
        vector<vector<int>> ans;

        dfs(nums, 0, segment, ans);

        return ans;    
    }
};
