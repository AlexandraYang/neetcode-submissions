class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = nums[0];
        int curMax = 1, curMin = 1;
        for (int i = 0; i < nums.size(); ++i) {
            int tmp = curMax * nums[i];

            curMax = max(nums[i], max(curMax*nums[i], curMin* nums[i]));
            curMin = min(nums[i], min(tmp, curMin* nums[i]));

            if (curMax > ans) {
                ans = curMax;
            }
        
        }

        return ans;
    }
};
