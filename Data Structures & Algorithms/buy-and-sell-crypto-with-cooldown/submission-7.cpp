class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) {
            return 0;
        }

        //dp[i][1] => 第i天可以買
        //dp[i][0] => 第i天可以賣
        vector<vector<int>> dp(n+2, vector<int>(2,0));

        for (int i = n-1; i >= 0; i--) {
            // state 1: 1 是可以買
            dp[i][1] = max(
                dp[i+1][0] - prices[i],   //今天買成本是price[i] 但明天可以賣
                dp[i+1][1] //今天不買 隔天繼續憂鬱要不要買
                );

            // state 2: 0 是可以賣 手上有股票
            dp[i][0] = max(
                dp[i+2][1] + prices[i], //今天賣 兩天後才能買 但可以賺今天的錢
                dp[i+1][0]  //今天不賣 隔天繼續憂鬱不賣
            );
        }

        return dp[0][1]; //從第0天開始 沒股票可以開始買
    }
};
