class Solution {
private: 
    void dfs(vector<int> &nums, vector<vector<int>> &ans, vector<int> tmp , int start) 
    {
       ans.push_back(tmp);
       for(int i=start; i< nums.size();++i) {
           tmp.push_back(nums[i]);
           dfs(nums, ans, tmp, i+1);
           tmp.pop_back();
       }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> tmp;
        vector<vector<int>> ans;
        dfs(nums, ans, tmp, 0);
        return ans;
    }
};

