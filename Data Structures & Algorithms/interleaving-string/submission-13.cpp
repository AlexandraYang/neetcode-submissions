class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size();
        int n = s2.size();
 
        if (m + n != s3.size()) {
            return false;
        }

        // dp i j 代表s1 前i 個 和 s2 前j 個是否可以組出s3 的i + j 個
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
        dp[0][0] = true; //i = 0, j = 0, 空字串 

        // i and j 是取幾個字 
        // i = m, 取m個字

        /*
        只要你看到這種定義：
        dp[i][j] = 前 i 個 + 前 j 個
        那你就應該立刻反射：

        dp 大小 = (m+1) × (n+1)
        loop = i <= m, j <= n
        這是模板級別的反射。
        */
        for (int i = 0; i <= m; ++i) {
            for (int j = 0; j <= n; ++j) {
                if ( i > 0 && dp[i-1][j] && s1[i-1] == s3[i+j-1]) {
                    dp[i][j] = true;
                }

                if(j >0 && dp[i][j-1] && s2[j-1] == s3[i+j-1]) {
                    dp[i][j] = true;
                }
            }
        }

        return dp[m][n];
    }
};
