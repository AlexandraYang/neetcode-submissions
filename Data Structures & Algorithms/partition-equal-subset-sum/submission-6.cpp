class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(auto &c: nums) {
            sum += c;
        }

        if (sum % 2 != 0) {
            return false;
        }

        int target = sum/2;
        vector<bool> dp(target+1, false);
        dp[0] = true;
        for (auto &num: nums) {
            for (int i = target; i >= num; --i) {
                dp[i] = dp[i] || dp[i - num];
            }
        }

        return dp[target];
    }
};
