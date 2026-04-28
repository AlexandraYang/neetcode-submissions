class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
         //dp[i][j] 代表text1前i個和text2 前j的LCS長度
        //需要處理 空字串問題 dp 想成是長度才會正確
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));


        for(int i = 1; i <= m; ++i) {
            for (int j =1; j <= n; ++j) {
                if (text1[i-1] == text2[j-1]) {
                    dp[i][j] = dp[i-1][j-1] +1;
                } else {
                    dp[i][j] = max(dp[i][j-1] , dp[i-1][j]);
                }
            }
        }

        return dp[m][n];
    }
};
