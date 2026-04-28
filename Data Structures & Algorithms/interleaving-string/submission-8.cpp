class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) {
            return false;
        }

        int m = s1.size();
        int n = s2.size();


        //dp[i][j] 代表 前 i 個 + 前 j 個, 所以範圍是 0 ~ m
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        dp[0][0] = true; //s1 s2 空字串 還是可以組出s3
        for (int i = 0; i <= m; ++i) {
            for (int j = 0; j <= n; ++j) {
                //假設s3 最後一個字來自s1
                if (i> 0 && dp[i-1][j] && s1[i-1] == s3[i+j-1]) {
                    dp[i][j] = true;
                }

                //假設s3 最後一個字來自s2
                if(j > 0 && dp[i][j-1] && s2[j-1] == s3[i+j-1]) {
                    dp[i][j] = true;
                }

            }
        }

        return dp[m][n];
    }
};
