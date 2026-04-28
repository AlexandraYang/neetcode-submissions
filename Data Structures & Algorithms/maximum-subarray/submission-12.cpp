class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curMax = nums[0];
        int finMax = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            curMax = max(nums[i], nums[i]+curMax);
 
            finMax = max(finMax, curMax);
        }

        return finMax;
    }
};
