class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();

        // DP table: dp[i][j] = word1[i:] → word2[j:] 最少操作數
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // Base case: word1 空了 → 插入剩下的 word2
        for (int j = 0; j <= n; ++j)
            dp[m][j] = n - j;

        // Base case: word2 空了 → 刪掉剩下的 word1
        for (int i = 0; i <= m; ++i)
            dp[i][n] = m - i;

        // 填表: 從右下往左上
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (word1[i] == word2[j]) {
                    dp[i][j] = dp[i + 1][j + 1]; // 相等不用操作
                } else {
                    dp[i][j] = 1 + min(
                        dp[i + 1][j],               // delete
                        min(dp[i][j + 1], dp[i + 1][j + 1]) // insert, replace
                    );
                }
            }
        }

        return dp[0][0]; // 整個 word1 → 整個 word2 的最少操作數
    }
};
