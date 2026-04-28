class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();

        //dp[i][j] represent 前i個 in text1 跟 前j個 in text2 
        //的 max LCS 是多少
        vector<vector<int>> dp(m + 1, vector<int>(n+1, 0));

        for (int i = 1; i <=m; ++i ) {
            for (int j = 1; j <= n; ++j) {
                if (text1[i-1] == text2[j-1]) {
                    //假設text1 的前 i-1個 跟 text2 的前 j-1個是相同的話
                    // 可以直接加1
                    dp[i][j] = dp[i-1][j-1] + 1; 
                } else {    
                    //假設若不一樣的話 則需要比較大小
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        return dp[m][n];
    }
};
