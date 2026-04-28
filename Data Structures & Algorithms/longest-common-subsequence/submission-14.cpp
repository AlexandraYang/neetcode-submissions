class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();

        /*
        dp[i][j] = text1 前 i 個字
           和 text2 前 j 個字
           的 LCS 長度
        */
        vector<vector<int>> dp(m+1, vector<int> (n+1, 0));

        for(int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (text1[i-1] == text2[j-1]) {
                    //如果當前兩個字相同 → 接在之前的 LCS 後面
                    //相同 → 往左上 +1
                    dp[i][j] = dp[i-1][j-1] + 1; 
                } else {
                    // 如果不同 → 嘗試丟掉其中一個字
                    // 不同 → 往上或往左 取最大
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        return dp[m][n];
    }
};
