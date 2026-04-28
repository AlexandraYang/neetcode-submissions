class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));

        for (int i = 0; i < m; ++i) {
            dp[i][0] = 1;
        }

        for (int j = 0; j < n; ++j) {
            dp[0][j] = 1;
        }

        for(int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                //dp 當前i j 狀態 是由上一個狀態造成
                // i-1, j 就是當前i , j的往上一個-> 代表剛剛他是往下到i j 
                // i, (j-1) 也是當前i j 的往左一個 -> 代表剛剛他是往右到i j 
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }

        return dp[m-1][n-1];
    }
};
