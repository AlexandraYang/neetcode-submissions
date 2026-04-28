class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp (m , vector<int> (n, 1));

        //假設全部初始化為1的話其實不需要個別在初始了
        //全部初始為一  這樣中間裡面的值會被蓋掉 所以其實是OKAY DER
        // for (int i = 0; i <= m; ++i) {
        //     dp[i][0] = 1;
        // }

        // for (int j = 0; j <= n; ++j) {
        //     dp[0][j] = 1;
        // } 
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n ; ++j) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }

        return dp[m-1][n-1];
    }
};
