class Solution {
private:
    int helper(vector<int>& nums, int start, int end) {
        int len = end - start +1;

        if (len == 1) {
            return nums[start];
        }

        vector<int> dp(len);
        dp[0] = nums[start];
        dp[1] = max(nums[start], nums[start+1]);

        for (int i = 2; i < len; ++i) {
            dp[i] = max(dp[i-2]+nums[start + i], dp[i-1]);
        }

        return dp[len-1];
    }

public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        if (len == 0) {
            return 0;
        }
        if (len == 1) {
            return nums[0];
        }

        if (len == 2) {
            return max(nums[0], nums[1]);
        }

        int case1 = helper(nums, 0, len-2);
        int case2 = helper(nums, 1, len-1);

        return max(case1, case2);
    }
};
