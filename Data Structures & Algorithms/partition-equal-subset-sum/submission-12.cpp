class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int sum = 0;
        for (int c : nums) {
            sum += c;
        }

        //假設數字非偶數  則必然無法
        if (sum % 2 != 0) {
            return false;
        }

        int target = sum / 2;
        
        vector<bool> dp(target + 1, false);
        dp[0] = true;

        for (int n : nums) {
            for (int i = target; i >= n; --i) {
                dp[i] = dp[i] || dp[i - n];
            }
        }

        return dp[target];
    }
};
