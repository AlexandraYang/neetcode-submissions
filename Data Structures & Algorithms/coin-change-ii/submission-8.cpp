class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1, 0);  // dp[i] = 使用目前 coin，湊出金額 i 的方法數
        dp[0] =1 ;
        for (auto & c : coins) {
            //在 Coin Change II 中，dp[i] += dp[i - c] 的前提是
            // 金額 i 至少能放下一個 coin c（i ≥ c），
            // 因此內層金額迴圈必須從 c 開始到 amount，否則該轉移在語意上不成立。
            for (int i = c; i <= amount; ++i) {
                //「再放一個 coin c」到金額 i - c 的所有組合後面
                dp[i] += dp[i-c];
            }
        }

        return dp[amount];
    }
};
