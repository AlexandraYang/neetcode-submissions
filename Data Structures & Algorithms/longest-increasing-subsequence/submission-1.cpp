class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, 1);

        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    int candidate = dp[j] + 1; // 可以+1是因為j可以接上
                    if (candidate > dp[i]) {
                        dp[i] = max(dp[i],candidate);
                    }
                    
                }
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};
