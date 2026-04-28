class Solution {
private:
    vector<int> mem;
    int dfs(vector<int>& nums, int start) {
        if (start >= nums.size()) {
            return 0;
        }

        if (mem[start]!= -1) {
            return mem[start];
        }

        mem[start] = max(dfs(nums, start+1), nums[start]+dfs(nums, start+2));

        return mem[start];
    }
    
public:
    int rob(vector<int>& nums) {
        mem.resize(nums.size(), -1);
        return dfs(nums, 0);
    }
};
