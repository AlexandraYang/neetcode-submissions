class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1, 0);
        dp[0] =1 ;
        for (auto & c : coins) {
            for (int i = c; i <= amount ; ++i) {
                // dp[i] = 使用目前 coin，湊出金額 i 的方法數
                dp[i] += dp[i-c];
            }
        }

        return dp[amount];
    }
};
