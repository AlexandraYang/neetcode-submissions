class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) {
            return 0;
        }

        //dp[i][1]: 第i天開始，可以買
        //dp[i][0]: 第i天開始，可以賣
        vector<vector<int>> dp(n+2, vector<int>(2,0));

        //最後一天往前推
        for (int i = n -1; i >= 0; --i) {
            //state1: 可以買
            dp[i][1] = max(
                //今天買 付出成本 ；但隔天可以賣
                dp[i+1][0] - prices[i],
                //今天不買
                dp[i+1][1]
            );

            //state2: 可以賣
            dp[i][0] = max(
                //今天賣的話  要等一天coldown 跟賺到現在價錢
                dp[i+2][1] + prices[i],
                //今天不賣 隔天繼續糾結
                dp[i+1][0] 
            );
        }

        return dp[0][1];//從第i天 沒股票可以買開始
    }
};
