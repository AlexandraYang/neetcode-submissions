class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int m = prices.size();

        if (m == 0) {
            return 0;
        }

        // dp[i][j] , i 是第i天開始 , j = 1 可以買；j = 0 可以賣 
        vector<vector<int>> dp (m+2, vector<int> (2, 0));

        for (int i = m -1; i >= 0; --i) {
            // case 1: 可以買股票, 但買了要考慮成本 || 不買的話 隔天還可以繼續買
            dp[i][1] = max(dp[i+1][0] - prices[i], dp[i+1][1]);

            // case 2: 不可以買股票 但可以賣 || 這次不賣
            dp[i][0] = max(dp[i+2][1] + prices[i], dp[i+1][0]);
        }

        return dp[0][1];
    }
};
