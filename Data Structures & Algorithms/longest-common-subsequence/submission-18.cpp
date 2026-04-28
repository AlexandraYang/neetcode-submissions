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
                    /*
                    // 如果 text1[i-1] == text2[j-1]
                    // 表示這個字元可以接在
                    // dp[i-1][j-1] 的 LCS 後面
                    // 因此長度 +1       
                    */
                    dp[i][j] = dp[i-1][j-1] + 1; 
                } else {    
                    //假設若不一樣的話 則需要比較大小
                    /*
                    // 如果當前字元不同
                    // 那麼 LCS 不可能同時包含這兩個字元
                    // 我們只能選擇：
                    // 1️⃣ 忽略 text1[i-1]
                    // 2️⃣ 忽略 text2[j-1]
                    // 取兩種情況的最大值
                    
                    */
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        return dp[m][n];
    }
};
