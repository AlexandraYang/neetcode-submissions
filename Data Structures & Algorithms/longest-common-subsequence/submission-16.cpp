class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();

        /*
        NOTE: dp index 是「長度」
        string index 是「位置」
        
        */

        vector<vector<int>> dp(m + 1, vector<int> (n+1, 0));
        /*
        為什麼 for loop 從 1 開始？
        因為我們的 dp 定義是：

        dp[i][j] = text1 前 i 個字
           text2 前 j 個字
           的 LCS 長度

        那「前 0 個字」是什麼？👉 空字串。
        */
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (text1[i-1] == text2[j-1]) {
                    dp[i][j] = dp[i-1][j-1]+1;
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        /*
        dp[i][j] = 前 i 個字
        text1 前 m 個字
        text2 前 n 個字

        */
        return dp[m][n];
    }
};
