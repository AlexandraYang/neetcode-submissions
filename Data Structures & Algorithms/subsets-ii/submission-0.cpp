class Solution {
private:
    void dfs(vector<int>& nums, vector<int>& seg, vector<vector<int>>& ans, int start) {
        ans.push_back(seg);

        for (int i = start; i < nums.size(); ++i) {
            if (i > start && nums[i] == nums[i-1]) {
                 // 跳過同層的重複，start 是層
                 // i  是每一層的起始i
                continue;
            }

            seg.push_back(nums[i]);
            dfs(nums, seg, ans, i+1); // ✅ 改成 i + 1
            seg.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        vector<int> seg;

        dfs(nums, seg, ans, 0);

        return ans;
    }
};
