class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+2, vector<int>(2, 0)); //2D 天數+0|1 , 因為下面跑到i+2 所以宣告要n+2
        for (int i = n - 1; i >= 0; --i) {
            //state 1:
            //可以買
            dp[i][1] = max(
                //今天買了需支付prices[i] 但明天(i+1)可以賣
                dp[i+1][0] - prices[i],
                //繼續糾結今天不買的話
                dp[i+1][1]
            );


            //state 2: 
            //可以賣
            dp[i][0] = max(
                //假設今天賣了賺prices[i] 但要兩天後才能買
                dp[i+2][1] + prices[i],
                // 今天沒賣 明天繼續糾結
                dp[i+1][0]
            );
        }

        return dp[0][1];//第i天開始 可以買
    }
};
